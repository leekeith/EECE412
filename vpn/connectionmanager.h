#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QString>
#include "logging.h"
#include "encryptionhelper.h"

namespace Ui {
class ConnectionManager;
}

class ConnectionManager : public QObject
{
    Q_OBJECT
public:
    explicit ConnectionManager(QObject *parent = 0, Logging* log = 0, EncryptionHelper* enc = 0);

    // For now, all functions blobbed up in here for server + client.
    // Possibly clean this up later.

    //Server Functions

    bool listen(int port);
    void stopListen();

    //Client Functions

    void connectToServer(QString host, int port);
    void disconnect();


    bool send(QString message);

    void writeTCPConnectionStatus();

signals:
    // Server mode auto calls this when a client connects to its listening port
    bool isListening();

    void isConnected();
    void isDisconnected();


public slots:
    void onReceiveNewConnection();
    void onReceiveNewMessage();

private slots:
    void connectedTCPSocket();
    void disconnectedTCPSocket();
    void hostFoundTCPSocket();

private:

    // Store state of encryption.
    // READY = key established, ready to transmit securely.
    enum cryptoState {IDLE, READY};
    //State variables
    // TCPServer opens a port to listen for incoming tcp requests
    QTcpServer* serverListener;

    // TCPSockets actually establish a connection with other ports
    QTcpSocket* connectionSocket;

    Logging* log;
    EncryptionHelper* encryptionHelper;
    cryptoState state;
    QString hostname;
    int port;
    bool connected;
    bool listening;

};

#endif // CONNECTIONMANAGER_H
