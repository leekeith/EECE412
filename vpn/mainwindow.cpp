#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connectionmanager.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    log(new Logging(this))
{
    ui->setupUi(this);

    encryptionHelper = new EncryptionHelper(this, log);
    connectionManager = new ConnectionManager(this, log, encryptionHelper);
    connect(connectionManager, SIGNAL(isConnected()), this, SLOT(onConnected()));
    // Connect log with GUI textOutput
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
    QString inputHostName = ui->plainTextEdit_host->toPlainText();
    bool validIntegerPort;
    int port = ui->plainTextEdit_port->toPlainText().toInt(&validIntegerPort);
    QString portString;
    portString.setNum(port);

    QString inputPreSharedKey = ui->plainTextEdit_key->toPlainText();

    if (!validIntegerPort) {
        log->write("Invalid port input: " + portString);
    }

    if(serverMode) {
        log->write("Error: Not in client mode!");
    } else {
        connectionManager->connectToServer(inputHostName, port);

        // TODO: Mutual authenticate, Establish shared symmetric session key via DH key exchange
        // Implement as shown on slide 5
        // http://courses.ece.ubc.ca/412/sessions/EECE_412-07-key_exchange.pdf

        // Use a random generator to create Ra, Rb.

        // We have g^amodp in DH key-exchange

        // We have the pre-shared symmetric key entered from UI (Kab) in inputPreSharedKey
    }
}

void MainWindow::onConnected() {
    log->write("Established TCP connection!");
}

void MainWindow::on_pushButton_listen_clicked()
{
    bool validIntegerPort;
    int port = ui->plainTextEdit_port->toPlainText().toInt(&validIntegerPort);
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

void MainWindow::keyPressEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
        this->on_pushButton_send_clicked();
    }
}

void MainWindow::on_pushButton_send_clicked()
{
    QString message = ui->plainTextEdit_message->toPlainText();
    ui->plainTextEdit_message->setPlainText("");
    // encryption is handled in connectionManager
    QString encryptedMessage = encryptionHelper->encryptMessage(message);
    connectionManager->send(encryptedMessage);
}

void MainWindow::on_pushButton_step_clicked()
{
    // TODO: implement the "Continue" button that steps through the connection setup
}
