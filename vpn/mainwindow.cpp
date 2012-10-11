#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "connectionmanager.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    log = new Logging(this);
    connectionManager = new ConnectionManager(this, log);

    connect(connectionManager, SIGNAL(isConnected()), this, SLOT(onConnected()));
    connect(log, SIGNAL(valueChanged(QString)), ui->textBrowser, SLOT(append(QString)));
    serverMode = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_checkBox_server_stateChanged(int checked)
{
    if(checked) {
        serverMode = true;
        log->write("In Server Mode");
        ui->pushButton_connect->setVisible(false);
        ui->pushButton_listen->setVisible(true);
    } else {
        serverMode = false;
        log->write("In Client Mode");
        ui->pushButton_connect->setVisible(true);
        ui->pushButton_listen->setVisible(false);
    }
}

void MainWindow::on_pushButton_connect_clicked()
{
    QString inputHostName = ui->plainTextEdit_host->document()->toPlainText();
    bool validIntegerPort;
    int port = ui->plainTextEdit_port->document()->toPlainText().toInt(&validIntegerPort);
    QString portString;
    portString.setNum(port);

    if (!validIntegerPort) {
        log->write("Invalid port input: " + portString);
    }

    if(serverMode) {
        log->write("Error: Not in client mode!");
    } else {
        connectionManager->connectToServer(inputHostName, port);
    }
}

void MainWindow::onConnected() {
    log->write("Established TCP connection!");
}

void MainWindow::on_pushButton_listen_clicked()
{
    bool validIntegerPort;
    int port = ui->plainTextEdit_port->document()->toPlainText().toInt(&validIntegerPort);
    QString portString;
    portString.setNum(port);

    if (!validIntegerPort) {
        log->write("Invalid port input: " + portString);
    }
    log->write("Start listening on port: " + portString);

    if(serverMode) {
        connectionManager->listen(port);
    } else {
        log->write("Error: Not in server mode!");
    }
}

void MainWindow::on_pushButton_send_clicked()
{
    // TODO:
    QString message = ui->plainTextEdit_message->document()->toPlainText();
    connectionManager->send(message, serverMode);
}

void MainWindow::on_pushButton_step_clicked()
{
    // TODO: implement the "Continue" button that steps through each step of the algorithm.
}
