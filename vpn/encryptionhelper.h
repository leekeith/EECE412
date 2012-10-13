#ifndef ENCRYPTIONHELPER_H
#define ENCRYPTIONHELPER_H

#include <QObject>
#include <random>
#include "logging.h"

// Class that contains encryption functions and state

class EncryptionHelper : public QObject
{
    Q_OBJECT
public:
    explicit EncryptionHelper(QObject *parent = 0, Logging* log = 0);
    
    // Put in encryption functions here
    unsigned long generatePartialDiffieHelmanKey();



signals:

public slots:
    
private:
    Logging * log;

    // Diffie Helman Key Exchange Constants
    int dhGenerator; // g
    int dhPrime; // p
    int secretInteger; // the random secret integer this client chooses
    unsigned long partialDiffieHelmanKey;
};

#endif // ENCRYPTIONHELPER_H
