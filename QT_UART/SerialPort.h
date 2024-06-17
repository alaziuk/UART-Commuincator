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

    qint64 write(QByteArray data);

    ~SerialPort();
private:
    QSerialPort *_serialPort;
    QByteArray buffer;

signals:
    void dataRecieved(QByteArray b);

private slots:
    void dataReady();
};

#endif // SERIALPORT_H
