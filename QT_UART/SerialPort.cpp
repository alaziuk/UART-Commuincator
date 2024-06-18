#include "SerialPort.h"

SerialPort::SerialPort(QObject *parent)
    : QObject{parent}
    , _serialPort(nullptr)
    , rx_buffer(QByteArray())
    , tx_buffer(QByteArray())
{

}

SerialPort::~SerialPort() {
    if (_serialPort != nullptr) {
        _serialPort->close();
        delete _serialPort;
    }
}

bool SerialPort::connect(QString portName) {
    if (_serialPort != nullptr) {
        _serialPort->close();
        delete _serialPort;
    }

    _serialPort = new QSerialPort(this);
    _serialPort->setPortName(portName);
    _serialPort->setBaudRate(QSerialPort::Baud9600);
    _serialPort->setDataBits(QSerialPort::Data8);
    _serialPort->setParity(QSerialPort::NoParity);
    _serialPort->setStopBits(QSerialPort::OneStop);

    if (_serialPort->open(QIODevice::ReadWrite)) {
        QObject::connect(_serialPort, &QSerialPort::readyRead, this, &SerialPort::dataReady);
    }

    return _serialPort->isOpen();
}

bool SerialPort::disconnect() {
    if (_serialPort != nullptr) {
        _serialPort->close();
        delete _serialPort;
    }
    _serialPort = nullptr;
    return true;
}

void SerialPort::dataReady() {
    if (_serialPort->isOpen()) {
        while(_serialPort->canReadLine()) {
            QByteArray line = _serialPort->readLine();
            if (!line.isEmpty()) {
                rx_buffer.append(line);

                if (rx_buffer.endsWith('\n') || rx_buffer.endsWith('r')) {
                    emit dataRecieved(rx_buffer);

                    rx_buffer.clear();
                }
            }
        }
    }
}

qint64 SerialPort::write(QByteArray data) {
    if (_serialPort == nullptr || !_serialPort->isOpen()) {
        return -1;
    }
    return _serialPort->write(data);;
}

QByteArray SerialPort::getMessage() {
    return tx_buffer;
}

void SerialPort::setMessage(int value) {
    tx_buffer.clear();

    tx_buffer.append("AT");
    if (value == 100) {
        tx_buffer.append(QString::number(value).toUtf8());
        return;
    }

    if (value < 100 && value >= 10) {
        tx_buffer.append("0");
        tx_buffer.append(QString::number(value).toUtf8());
        return;
    }

    tx_buffer.append("00");
    tx_buffer.append(QString::number(value).toUtf8());
    return;
}
