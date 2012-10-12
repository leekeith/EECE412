/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Oct 12 01:36:48 2012
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_connect;
    QPlainTextEdit *plainTextEdit_host;
    QLabel *label_host;
    QLabel *label_port;
    QPlainTextEdit *plainTextEdit_port;
    QTextBrowser *textBrowser;
    QPlainTextEdit *plainTextEdit_message;
    QPushButton *pushButton_send;
    QPlainTextEdit *plainTextEdit_key;
    QLabel *label_key;
    QPushButton *pushButton_listen;
    QCheckBox *checkBox_server;
    QPushButton *pushButton_step;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(435, 517);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton_connect = new QPushButton(centralWidget);
        pushButton_connect->setObjectName(QString::fromUtf8("pushButton_connect"));
        pushButton_connect->setGeometry(QRect(260, 30, 141, 41));
        plainTextEdit_host = new QPlainTextEdit(centralWidget);
        plainTextEdit_host->setObjectName(QString::fromUtf8("plainTextEdit_host"));
        plainTextEdit_host->setGeometry(QRect(40, 0, 181, 31));
        label_host = new QLabel(centralWidget);
        label_host->setObjectName(QString::fromUtf8("label_host"));
        label_host->setGeometry(QRect(10, 10, 31, 16));
        label_port = new QLabel(centralWidget);
        label_port->setObjectName(QString::fromUtf8("label_port"));
        label_port->setGeometry(QRect(10, 40, 31, 16));
        plainTextEdit_port = new QPlainTextEdit(centralWidget);
        plainTextEdit_port->setObjectName(QString::fromUtf8("plainTextEdit_port"));
        plainTextEdit_port->setGeometry(QRect(40, 30, 81, 31));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 100, 421, 311));
        plainTextEdit_message = new QPlainTextEdit(centralWidget);
        plainTextEdit_message->setObjectName(QString::fromUtf8("plainTextEdit_message"));
        plainTextEdit_message->setGeometry(QRect(10, 410, 331, 61));
        pushButton_send = new QPushButton(centralWidget);
        pushButton_send->setObjectName(QString::fromUtf8("pushButton_send"));
        pushButton_send->setGeometry(QRect(340, 440, 91, 31));
        plainTextEdit_key = new QPlainTextEdit(centralWidget);
        plainTextEdit_key->setObjectName(QString::fromUtf8("plainTextEdit_key"));
        plainTextEdit_key->setGeometry(QRect(40, 60, 181, 31));
        label_key = new QLabel(centralWidget);
        label_key->setObjectName(QString::fromUtf8("label_key"));
        label_key->setGeometry(QRect(10, 70, 31, 16));
        pushButton_listen = new QPushButton(centralWidget);
        pushButton_listen->setObjectName(QString::fromUtf8("pushButton_listen"));
        pushButton_listen->setGeometry(QRect(270, 70, 121, 31));
        checkBox_server = new QCheckBox(centralWidget);
        checkBox_server->setObjectName(QString::fromUtf8("checkBox_server"));
        checkBox_server->setGeometry(QRect(290, 0, 87, 21));
        pushButton_step = new QPushButton(centralWidget);
        pushButton_step->setObjectName(QString::fromUtf8("pushButton_step"));
        pushButton_step->setGeometry(QRect(340, 410, 91, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 435, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        pushButton_connect->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
        label_host->setText(QApplication::translate("MainWindow", "Host", 0, QApplication::UnicodeUTF8));
        label_port->setText(QApplication::translate("MainWindow", "Port", 0, QApplication::UnicodeUTF8));
        pushButton_send->setText(QApplication::translate("MainWindow", "Send", 0, QApplication::UnicodeUTF8));
        label_key->setText(QApplication::translate("MainWindow", "Key", 0, QApplication::UnicodeUTF8));
        pushButton_listen->setText(QApplication::translate("MainWindow", "Listen", 0, QApplication::UnicodeUTF8));
        checkBox_server->setText(QApplication::translate("MainWindow", "Server", 0, QApplication::UnicodeUTF8));
        pushButton_step->setText(QApplication::translate("MainWindow", "Step", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
