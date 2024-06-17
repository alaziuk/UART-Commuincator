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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btnPortsInfo;
    QComboBox *cmbPorts;
    QPushButton *btnOpenPort;
    QPushButton *btnSend;
    QLineEdit *lnMessage;
    QListWidget *lstMessages;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(883, 398);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        btnPortsInfo = new QPushButton(centralwidget);
        btnPortsInfo->setObjectName("btnPortsInfo");
        btnPortsInfo->setGeometry(QRect(40, 50, 80, 24));
        cmbPorts = new QComboBox(centralwidget);
        cmbPorts->setObjectName("cmbPorts");
        cmbPorts->setGeometry(QRect(140, 50, 141, 24));
        btnOpenPort = new QPushButton(centralwidget);
        btnOpenPort->setObjectName("btnOpenPort");
        btnOpenPort->setGeometry(QRect(300, 50, 80, 24));
        btnSend = new QPushButton(centralwidget);
        btnSend->setObjectName("btnSend");
        btnSend->setGeometry(QRect(300, 90, 80, 24));
        lnMessage = new QLineEdit(centralwidget);
        lnMessage->setObjectName("lnMessage");
        lnMessage->setGeometry(QRect(40, 90, 241, 23));
        lstMessages = new QListWidget(centralwidget);
        lstMessages->setObjectName("lstMessages");
        lstMessages->setGeometry(QRect(400, 50, 256, 192));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 883, 21));
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
        btnPortsInfo->setText(QCoreApplication::translate("MainWindow", "Ports", nullptr));
        btnOpenPort->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        btnSend->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
