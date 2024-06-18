#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QObject>
#include <QSerialPort>

class SerialPort : public QObject
{
    Q_OBJECT
public:
    explicit SerialPort(QObject *parent = nullptr);
    bool connect(QString portName);
    bool disconnect();
    qint64 write(QByteArray data);
    QByteArray getSpeed();
    QByteArray getType();
    void setSpeed(int value);
    void setType(QString value);
    ~SerialPort();
private:
    QSerialPort *_serialPort;
    QByteArray rxBuffer;
    QByteArray txBufferSpeed;
    QByteArray txBufferCommsType;

signals:
    void dataRecieved(QByteArray b);

private slots:
    void dataReady();
};

#endif // SERIALPORT_H
