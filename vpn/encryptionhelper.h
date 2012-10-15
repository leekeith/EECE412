#ifndef ENCRYPTIONHELPER_H
#define ENCRYPTIONHELPER_H

//#include <QObject>
#include <random>
//#include "logging.h"
#include<string>
#define NUM_ITT 12
#include<vector>

// Class that contains encryption functions and state

class EncryptionHelper //: public QObject
{
    //Q_OBJECT
public:
    explicit EncryptionHelper();//QObject *parent = 0, Logging* log = 0);
    
    // Put in encryption functions here
    
	void config_DH(std::string password);
	void gen_DH_key(unsigned long p_DH_key_recd);
	void config_feis();
	unsigned long get_p_DH_key();
	void feis_encode(char* text, char* otext, int size);
	void feis_decode(char* text, char* otext, int size);
	unsigned int gen_nonce();


//signals:

//public slots:
    
private:
    //Logging * log;

    // Diffie Helman Key Exchange Constants
    int dhGenerator; // g
    int dhPrime; // p
    int secretInteger; // the random secret integer this client chooses
    unsigned long p_DH_Key;
	unsigned long DH_Key;
	unsigned char keyset[NUM_ITT][32]; 
	std::vector<unsigned int> nonce;

	char feis_func(char in, int itt, int index);
	void gen_p_DH_key();

};

#endif // ENCRYPTIONHELPER_H
