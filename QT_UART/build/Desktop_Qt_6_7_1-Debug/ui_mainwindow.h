/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QComboBox *cmbPorts;
    QPushButton *btnOpenPort;
    QPushButton *btnSend;
    QListWidget *lstMessages;
    QSlider *sldrPercentage;
    QPushButton *btnClosePort;
    QLabel *lblSliderValue;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(694, 328);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        cmbPorts = new QComboBox(centralwidget);
        cmbPorts->setObjectName("cmbPorts");
        cmbPorts->setGeometry(QRect(40, 50, 241, 24));
        btnOpenPort = new QPushButton(centralwidget);
        btnOpenPort->setObjectName("btnOpenPort");
        btnOpenPort->setGeometry(QRect(300, 50, 80, 24));
        btnSend = new QPushButton(centralwidget);
        btnSend->setObjectName("btnSend");
        btnSend->setEnabled(false);
        btnSend->setGeometry(QRect(300, 90, 80, 24));
        lstMessages = new QListWidget(centralwidget);
        lstMessages->setObjectName("lstMessages");
        lstMessages->setGeometry(QRect(400, 50, 256, 192));
        sldrPercentage = new QSlider(centralwidget);
        sldrPercentage->setObjectName("sldrPercentage");
        sldrPercentage->setGeometry(QRect(40, 90, 241, 20));
        sldrPercentage->setMaximum(100);
        sldrPercentage->setOrientation(Qt::Horizontal);
        btnClosePort = new QPushButton(centralwidget);
        btnClosePort->setObjectName("btnClosePort");
        btnClosePort->setEnabled(false);
        btnClosePort->setGeometry(QRect(300, 220, 80, 24));
        lblSliderValue = new QLabel(centralwidget);
        lblSliderValue->setObjectName("lblSliderValue");
        lblSliderValue->setGeometry(QRect(310, 140, 56, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 694, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnOpenPort->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        btnSend->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        btnClosePort->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        lblSliderValue->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
