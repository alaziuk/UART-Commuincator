#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadPorts();
    connect(&_port, &SerialPort::dataRecieved, this, &MainWindow::readData);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadPorts()
{
    for (auto &port : QSerialPortInfo::availablePorts()) {
        ui->cmbPorts->addItem(port.portName());
    }
}

void MainWindow::on_btnOpenPort_clicked()
{
    auto isConnected = _port.connect(ui->cmbPorts->currentText());
    if (!isConnected) {
        QMessageBox::critical(this, "Error", "There is a problem connecting to a port");
    } else {
        ui->btnClosePort->setEnabled(true);
        ui->btnSend->setEnabled(true);
        QMessageBox::information(this, "Information", "Port was opened succesfully");
    }
}


void MainWindow::on_btnSend_clicked()
{
    auto numBytes = _port.write(_port.getMessage());
    if (numBytes == -1) {
        QMessageBox::critical(this, "Error", "Something went wrong");
    } else {
        QMessageBox::information(this, "Information", "Message was sent succesfully");
    }
}

void MainWindow::readData(QByteArray data)
{
    ui->lstMessages->addItem(data);
}

void MainWindow::on_btnClosePort_clicked()
{
    auto isDisconnected = _port.disconnect();
    if (!isDisconnected) {
        QMessageBox::critical(this, "Error", "There is a problem disconnecting from a port");
    } else {
        ui->btnClosePort->setEnabled(false);
        ui->btnSend->setEnabled(false);
        QMessageBox::information(this, "Information", "Port was closed succesfully");
    }
}
void MainWindow::on_sldrPercentage_valueChanged(int value)
{
    ui->lblSliderValue->setText(QString::number(value));
    _port.setMessage(value);
}
