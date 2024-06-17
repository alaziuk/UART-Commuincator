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
        QMessageBox::information(this, "Information", "Port was opened succesfully");
    }
}


void MainWindow::on_btnSend_clicked()
{
    auto numBytes = _port.write(ui->lnMessage->text().toUtf8());
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
