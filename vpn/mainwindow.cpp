#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    serverMode = false;
    connected = false;
    listening = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_checkBox_server_stateChanged(int checked)
{
    if(checked) {
        serverMode = true;
        qDebug() << "In Server Mode";
        ui->pushButton_connect->setText("Listen");
    } else {
        serverMode = false;
        qDebug() << "In Client Mode";
        ui->pushButton_connect->setText("Connect");
    }
}
