#include "encryptionhelper.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "feistel.h"

const int MAX_SECRET_INTEGER = 30;

EncryptionHelper::EncryptionHelper(QObject *parent, Logging* log) :
    QObject(parent)
{
    this->log = log;

    // Initialize Diffie Helman key exchange constants
    this->dhGenerator = 5;
    this->dhPrime = 23;
    // Initialize random number generator seed
    std::srand(std::time(0));
}


unsigned long EncryptionHelper::generatePartialDiffieHelmanKey() {

    // generate secret integer a
    secretInteger = std::rand() % MAX_SECRET_INTEGER;

    // Calculate g^a mod p, and store it for calculating the session key later.
    partialDiffieHelmanKey = ((unsigned long) std::pow((double)dhGenerator, secretInteger)) % dhPrime;
    return partialDiffieHelmanKey;
}


QString EncryptionHelper::encryptMessage(const QString& message) {

    // encrypt message using symmetric key feistel cipher

    // computer hash checksum using md5 / sha1 or something

    return "dummy";
}

QString EncryptionHelper::decryptMessage(const QString& message) {
    // decrypt message using symmetric key feistel cipher

    // computer hash checksum of the message part, and compare the checksums for corruption

    return "dummy";
}
