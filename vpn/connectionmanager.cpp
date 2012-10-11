
#include "connectionmanager.h"

ConnectionManager::ConnectionManager(QObject *parent, Logging* log) :
    QObject(parent)
{
    serverListener = new QTcpServer(this);
    connectionSocket = new QTcpSocket(this);
    connect(serverListener, SIGNAL(newConnection()), this, SLOT(onReceiveNewConnection()));
    connect(connectionSocket, SIGNAL(hostFound()), this, SLOT(hostFoundTCPSocket()));
    connect(connectionSocket, SIGNAL(connected()), this, SLOT(connectedTCPSocket()));
    connect(connectionSocket, SIGNAL(disconnected()), this, SLOT(disconnectedTCPSocket()));
    this->log = log;
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
    } else {
        log->write("Started listening");
    }
}

void ConnectionManager::stopListen() {
    if (serverListener->isListening()) {
        serverListener->close();
    }
}

bool ConnectionManager::send(QString message, bool serverMode) {
    int result;
    if (serverMode) {
        result = serverSocket->write(message.toAscii());
    } else {
        result = connectionSocket->write(message.toAscii());
    }
    if (result < 0) {
        log->write("Failed to send");
        return false;
    } else {
        log->write("Sent");
        return true;
    }
}

bool ConnectionManager::disconnect() {
    if (!connectionSocket->state() != QAbstractSocket::UnconnectedState) {
        connectionSocket->disconnectFromHost();
    }
    if (!connectionSocket->state() != QAbstractSocket::UnconnectedState) {
        connectionSocket->disconnectFromHost();
    }
}

void ConnectionManager::hostFoundTCPSocket() {
    log->write("Target host found, attempting to connect...");
}

void ConnectionManager::connectedTCPSocket() {
    emit isConnected();
}

void ConnectionManager::disconnectedTCPSocket() {
    emit isDisconnected();
}

void ConnectionManager::onReceiveNewConnection() {
    log->write("New connection");
    serverSocket = serverListener->nextPendingConnection();
    serverSocket->write("connected!\r\n");
    serverSocket->flush();
}
