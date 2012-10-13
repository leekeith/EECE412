/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat Oct 13 02:22:35 2012
**      by: Qt User Interface Compiler version 4.8.1
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
#include <QtGui/QGridLayout>
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
    QTextBrowser *textBrowser;
    QPlainTextEdit *plainTextEdit_message;
    QPushButton *pushButton_send;
    QPushButton *pushButton_listen;
    QCheckBox *checkBox_server;
    QPushButton *pushButton_step;
    QWidget *widget;
    QGridLayout *gridLayout_connectionInfo;
    QLabel *label_host;
    QPlainTextEdit *plainTextEdit_host;
    QLabel *label_port;
    QPlainTextEdit *plainTextEdit_port;
    QLabel *label_key;
    QPlainTextEdit *plainTextEdit_key;
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
        pushButton_connect->setGeometry(QRect(270, 60, 131, 31));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 100, 421, 311));
        plainTextEdit_message = new QPlainTextEdit(centralWidget);
        plainTextEdit_message->setObjectName(QString::fromUtf8("plainTextEdit_message"));
        plainTextEdit_message->setGeometry(QRect(10, 410, 331, 51));
        plainTextEdit_message->setTabChangesFocus(true);
        pushButton_send = new QPushButton(centralWidget);
        pushButton_send->setObjectName(QString::fromUtf8("pushButton_send"));
        pushButton_send->setGeometry(QRect(340, 410, 91, 51));
        pushButton_listen = new QPushButton(centralWidget);
        pushButton_listen->setObjectName(QString::fromUtf8("pushButton_listen"));
        pushButton_listen->setGeometry(QRect(270, 60, 131, 31));
        checkBox_server = new QCheckBox(centralWidget);
        checkBox_server->setObjectName(QString::fromUtf8("checkBox_server"));
        checkBox_server->setGeometry(QRect(310, 0, 87, 21));
        pushButton_step = new QPushButton(centralWidget);
        pushButton_step->setObjectName(QString::fromUtf8("pushButton_step"));
        pushButton_step->setGeometry(QRect(270, 20, 131, 31));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 0, 241, 91));
        gridLayout_connectionInfo = new QGridLayout(widget);
        gridLayout_connectionInfo->setSpacing(6);
        gridLayout_connectionInfo->setContentsMargins(11, 11, 11, 11);
        gridLayout_connectionInfo->setObjectName(QString::fromUtf8("gridLayout_connectionInfo"));
        gridLayout_connectionInfo->setContentsMargins(0, 0, 0, 0);
        label_host = new QLabel(widget);
        label_host->setObjectName(QString::fromUtf8("label_host"));

        gridLayout_connectionInfo->addWidget(label_host, 0, 0, 1, 1);

        plainTextEdit_host = new QPlainTextEdit(widget);
        plainTextEdit_host->setObjectName(QString::fromUtf8("plainTextEdit_host"));
        plainTextEdit_host->setTabChangesFocus(true);

        gridLayout_connectionInfo->addWidget(plainTextEdit_host, 0, 1, 1, 1);

        label_port = new QLabel(widget);
        label_port->setObjectName(QString::fromUtf8("label_port"));

        gridLayout_connectionInfo->addWidget(label_port, 1, 0, 1, 1);

        plainTextEdit_port = new QPlainTextEdit(widget);
        plainTextEdit_port->setObjectName(QString::fromUtf8("plainTextEdit_port"));
        plainTextEdit_port->setTabChangesFocus(true);

        gridLayout_connectionInfo->addWidget(plainTextEdit_port, 1, 1, 1, 1);

        label_key = new QLabel(widget);
        label_key->setObjectName(QString::fromUtf8("label_key"));

        gridLayout_connectionInfo->addWidget(label_key, 2, 0, 1, 1);

        plainTextEdit_key = new QPlainTextEdit(widget);
        plainTextEdit_key->setObjectName(QString::fromUtf8("plainTextEdit_key"));
        plainTextEdit_key->setTabChangesFocus(true);

        gridLayout_connectionInfo->addWidget(plainTextEdit_key, 2, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        pushButton_listen->raise();
        pushButton_connect->raise();
        plainTextEdit_host->raise();
        label_host->raise();
        label_port->raise();
        plainTextEdit_port->raise();
        textBrowser->raise();
        plainTextEdit_message->raise();
        pushButton_send->raise();
        plainTextEdit_key->raise();
        label_key->raise();
        checkBox_server->raise();
        pushButton_step->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 435, 21));
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
        pushButton_send->setText(QApplication::translate("MainWindow", "Send", 0, QApplication::UnicodeUTF8));
        pushButton_listen->setText(QApplication::translate("MainWindow", "Listen", 0, QApplication::UnicodeUTF8));
        checkBox_server->setText(QApplication::translate("MainWindow", "Server", 0, QApplication::UnicodeUTF8));
        pushButton_step->setText(QApplication::translate("MainWindow", "Step through Connect", 0, QApplication::UnicodeUTF8));
        label_host->setText(QApplication::translate("MainWindow", "Host", 0, QApplication::UnicodeUTF8));
        label_port->setText(QApplication::translate("MainWindow", "Port", 0, QApplication::UnicodeUTF8));
        label_key->setText(QApplication::translate("MainWindow", "Key", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
