#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>
#include <cstdio>
#include <cstring>

int main() {
    int serial_port = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_EXCL);

    if (serial_port < 0) {
        perror("Error opening serial port");
        return 1;
    }

    struct termios tty;
    memset(&tty, 0, sizeof tty);

    if (tcgetattr(serial_port, &tty)!= 0) {
        perror("Error from tcgetattr: ");
        return 1;
    }

    cfsetispeed(&tty, B9600);
    cfsetospeed(&tty, B9600);

    tty.c_cflag &= ~PARENB; // Clear parity bit, disabling parity (common)
    tty.c_cflag &= ~CSTOPB; // Clear stop field, only one stop bit used in communication (common)
    tty.c_cflag &= ~CSIZE; // Clear all bits that set the data size
    tty.c_cflag |= CS8; // 8 bits per byte (most common)
    tty.c_cflag &= ~CRTSCTS; // Disable RTS/CTS hardware flow control (common)
    tty.c_cflag |= CREAD | CLOCAL; // Turn on READ & ignore ctrl lines (CLOCAL = 1)

    tty.c_lflag &= ~ICANON;
    tty.c_lflag &= ~ECHO; // Disable echo
    tty.c_lflag &= ~ECHOE; // Disable erasure
    tty.c_lflag &= ~ECHONL; // Disable new-line echo
    tty.c_lflag &= ~ISIG; // Disable interpretation of INTR, QUIT and SUSP

    tty.c_iflag &= ~(IXON | IXOFF | IXANY); // Turn off s/w flow ctrl
    tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INPCK|IGNCR|ICRNL);

    tty.c_oflag &= ~OPOST; // Prevent special interpretation of output bytes (e.g. newline chars)
    tty.c_oflag &= ~ONLCR; // Prevent conversion of newline to carriage return/line feed

    tty.c_cc[VTIME] = 100; // Wait for up to 1s (10 deciseconds), returning as soon as any data is received.
    tty.c_cc[VMIN] = 0;

    if (tcsetattr(serial_port, TCSANOW, &tty)!= 0) {
        perror("Error from tcsetattr: ");
        return 1;
    }

    // Write to serial port
    const unsigned char msg[] = {'A', 'T', '0', '9', '0', '\r', '\n'};
    write(serial_port, msg, sizeof(msg));

    // Allocate memory for read buffer
    char read_buf[1024];
    memset(read_buf, '\0', sizeof(read_buf));

    // Read bytes
    int num_bytes = read(serial_port, read_buf, sizeof(read_buf));

    if (num_bytes < 0) {
        perror("Error reading: ");
        return 1;
    }

    printf("Read %i bytes. Received message: %s\n", num_bytes, read_buf);

    close(serial_port);
    return 0; // Success

}
