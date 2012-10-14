
#include "connectionmanager.h"


ConnectionManager::ConnectionManager(QObject *parent, Logging* log, EncryptionHelper* enc) :
    QObject(parent)
{
    serverListener = new QTcpServer(this);
    connectionSocket = new QTcpSocket(this);
    connect(serverListener, SIGNAL(newConnection()), this, SLOT(onReceiveNewConnection()));
    connect(connectionSocket, SIGNAL(hostFound()), this, SLOT(hostFoundTCPSocket()));
    connect(connectionSocket, SIGNAL(connected()), this, SLOT(connectedTCPSocket()));
    connect(connectionSocket, SIGNAL(disconnected()), this, SLOT(disconnectedTCPSocket()));
    connect(connectionSocket, SIGNAL(readyRead()), this, SLOT(onReceiveNewMessage()));
    this->log = log;
    encryptionHelper = enc;
    state = IDLE;
}

void ConnectionManager::connectToServer(QString host, int port) {
    if (!connectionSocket->state() != QAbstractSocket::UnconnectedState) {
        connectionSocket->disconnectFromHost();
    }

    connectionSocket->connectToHost(host, port);
}

bool ConnectionManager::listen(int port) {

    if (serverListener->isListening()) {
        log->write("Already listening");
    }

    if(!serverListener->listen(QHostAddress::Any, port)) {
        log->write("Failed to start listening");
        log->write(serverListener->errorString());
        qDebug() << serverListener->errorString();
        return false;
    } else {
        log->write("Started listening");
        return true;
    }
}

void ConnectionManager::stopListen() {
    if (serverListener->isListening()) {
        serverListener->close();
    }
}

bool ConnectionManager::send(QString message) {
    int result;

    result = connectionSocket->write(message.toAscii());

    if (result < 0) {
        log->write("Failed to send");
        return false;
    } else {
        log->write("Sent: " + message);
        return true;
    }
}

void ConnectionManager::disconnect() {
    if (!connectionSocket->state() != QAbstractSocket::UnconnectedState) {
        connectionSocket->disconnectFromHost();
    }
}

void ConnectionManager::hostFoundTCPSocket() {
    log->write("Target host found, attempting to connect...");
}

void ConnectionManager::connectedTCPSocket() {
    log->write("TCP Socket Connected!");
    this->writeTCPConnectionStatus();
    emit isConnected();
}

void ConnectionManager::disconnectedTCPSocket() {
    emit isDisconnected();
}

void ConnectionManager::onReceiveNewConnection() {
    // When receiving a new connection, delete old connection first
    this->disconnect();
    delete connectionSocket;

    connectionSocket = serverListener->nextPendingConnection();
    connect(connectionSocket, SIGNAL(hostFound()), this, SLOT(hostFoundTCPSocket()));
    connect(connectionSocket, SIGNAL(connected()), this, SLOT(connectedTCPSocket()));
    connect(connectionSocket, SIGNAL(disconnected()), this, SLOT(disconnectedTCPSocket()));
    connect(connectionSocket, SIGNAL(readyRead()), this, SLOT(onReceiveNewMessage()));
    log->write("New connection from: " + connectionSocket->peerAddress().toString());
    this->writeTCPConnectionStatus();
}

void ConnectionManager::onReceiveNewMessage() {
    QString receivedMessage = connectionSocket->readAll();

    // use state machine to see which phase of protocol we are in

    if (state == READY) {
        // only when state is ready is the
        QString decryptedMessage = encryptionHelper->decryptMessage(receivedMessage);
        log->write("Receieved: " + decryptedMessage);
    }
}

void ConnectionManager::writeTCPConnectionStatus() {
    log->write("Local Address: " + connectionSocket->localAddress().toString() + ":" +
               QString::number(connectionSocket->localPort()) + ", Peer Address: " +
               connectionSocket->peerAddress().toString() + ":" + QString::number(connectionSocket->peerPort()));
}
