#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadPorts();
    loadTypes();
    setWindowTitle("Motor Control");
    setFixedSize(QSize(694, 328));
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

void MainWindow::loadTypes() {
    QStringList typeList = {"None", "PWM", "CAN"};
    ui->cmbCommsType->addItems(typeList);
    ui->cmbCommsType->setCurrentIndex(0);
}

void MainWindow::enableWidgets(bool open) {
    ui->btnClosePort->setEnabled(open);
    ui->btnSend->setEnabled(open);
    ui->btnCommsType->setEnabled(open);
    ui->cmbCommsType->setEnabled(open);
    ui->lblSliderValue->setEnabled(open);
    ui->btnAskType->setEnabled(open);
}

void MainWindow::on_btnOpenPort_clicked()
{
    auto isConnected = _port.connect(ui->cmbPorts->currentText());
    if (!isConnected) {
        QMessageBox::critical(this, "Error", "There is a problem connecting to a port");
    } else {
        enableWidgets(true);
        QMessageBox::information(this, "Information", "Port was opened succesfully");
    }
}


void MainWindow::on_btnSend_clicked()
{
    auto numBytes = _port.write(_port.getSpeed());
    if (numBytes == -1) {
        QMessageBox::critical(this, "Error", "Something went wrong");
    } else {
        QMessageBox::information(this, "Information", "Reference speed was sent succesfully");
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
        enableWidgets(false);
        QMessageBox::information(this, "Information", "Port was closed succesfully");
    }
}
void MainWindow::on_sldrPercentage_valueChanged(int value)
{
    ui->lblSliderValue->setText(QString::number(value));
    _port.setSpeed(value);
}

void MainWindow::on_btnCommsType_clicked()
{
    _port.setType(ui->cmbCommsType->currentText());
    auto numBytes = _port.write(_port.getType());
    if (numBytes == -1) {
        QMessageBox::critical(this, "Error", "Something went wrong");
    } else {
        QMessageBox::information(this, "Information", "Comms type was sent succesfully");
    }
}


void MainWindow::on_btnAskType_clicked()
{
    _port.setType("WHT");
    auto numBytes = _port.write(_port.getType());
    if (numBytes == -1) {
        QMessageBox::critical(this, "Error", "Something went wrong");
    } else {
        QMessageBox::information(this, "Information", "Type request was sent succesfully");
    }
}

