#include "encryptionhelper.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

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
