#include "SerialPort.h"

SerialPort::SerialPort(QObject *parent)
    : QObject{parent}
    , _serialPort(nullptr)
    , rxBuffer(QByteArray())
    , txBufferSpeed(QByteArray())
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
                rxBuffer.append(line);

                if (rxBuffer.endsWith('\n') || rxBuffer.endsWith('r')) {
                    emit dataRecieved(rxBuffer);

                    rxBuffer.clear();
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

QByteArray SerialPort::getSpeed() {
    return txBufferSpeed;
}

void SerialPort::setSpeed(int value) {
    txBufferSpeed.clear();

    txBufferSpeed.append("AT");
    if (value == 100) {
        txBufferSpeed.append(QString::number(value).toUtf8());
        return;
    }

    if (value < 100 && value >= 10) {
        txBufferSpeed.append("0");
        txBufferSpeed.append(QString::number(value).toUtf8());
        return;
    }

    txBufferSpeed.append("00");
    txBufferSpeed.append(QString::number(value).toUtf8());
    return;
}

QByteArray SerialPort::getType() {
    return txBufferCommsType;
}

void SerialPort::setType(QString value) {
    txBufferCommsType.clear();

    txBufferCommsType.append("AT");
    if (value == "None") {
        txBufferCommsType.append("NON");
        return;
    }

    if (value == "PWM") {
        txBufferCommsType.append("PWM");
        return;
    }

    if (value == "CAN") {
        txBufferCommsType.append("CAN");
        return;
    }

    if (value == "WHT") {
        txBufferCommsType.append("WHT");
        return;
    }
}
