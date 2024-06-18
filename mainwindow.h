#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "SerialPort.h"
#include <QSerialPortInfo>
#include <QDebug>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnOpenPort_clicked();
    void on_btnSend_clicked();
    void readData(QByteArray data);
    void on_btnClosePort_clicked();
    void on_sldrPercentage_valueChanged(int value);

    void on_btnCommsType_clicked();

    void on_btnAskType_clicked();

private:
    Ui::MainWindow *ui;
    SerialPort _port;
    void loadPorts();
    void loadTypes();
    void enableWidgets(bool open);
};
#endif // MAINWINDOW_H
