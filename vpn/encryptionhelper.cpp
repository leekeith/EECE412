#include "encryptionhelper.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include<limits>

const unsigned int MAX_SECRET_INTEGER = 8;

EncryptionHelper::EncryptionHelper()//QObject *parent, Logging* log) :
    //QObject(parent)
{
    //this->log = log;

    // Initialize Diffie Helman key exchange constants
    this->dhGenerator = 1;
    this->dhPrime = 3571;
	this->p_DH_Key=0;
	this->DH_Key=0;
    // Initialize random number generator seed
    std::srand(std::time(0));
}

unsigned long EncryptionHelper::get_p_DH_key()
{
	return this->p_DH_Key;
}
void EncryptionHelper::gen_p_DH_key() {

    // generate secret integer a
    this->secretInteger = (std::rand() % MAX_SECRET_INTEGER)+1;

    // Calculate g^a mod p, and store it for calculating the session key later.
    this->p_DH_Key=((unsigned long)(std::pow((long double)this->dhGenerator, this->secretInteger)))%this->dhPrime;
	
}

void EncryptionHelper::config_DH(std::string password)
{
	for(int i=0;i<password.size();i++)
	{
		this->dhGenerator+=(password[i]+password[(2*i+1)%(password.size()-1)])/(i+1);
	}
	this->gen_p_DH_key();
}

void EncryptionHelper::gen_DH_key(unsigned long p_DH_key_recd)
{
	this->DH_Key=((unsigned long)(std::pow((long double)p_DH_key_recd, this->secretInteger)))%this->dhPrime;
}

void EncryptionHelper::config_feis()
{
	int i,j;
	for(i=0;i<NUM_ITT;i++)
	{
		for(j=0;j<32;j++)
			this->keyset[i][j]=((unsigned long)(std::pow((long double)(2*this->DH_Key%(64+i)),((j+1)%8)+1)+this->DH_Key+j))%UCHAR_MAX;
	}
}

char EncryptionHelper::feis_func(char in, int itt, int index)
{
	return (in*this->keyset[itt][index%32]%UCHAR_MAX);
}

void EncryptionHelper::feis_encode(char* text,char* otext,int size)
{
	char* L[NUM_ITT];
	char* R[NUM_ITT];
	int numchars;
	
	
	numchars=size;
	


	int i,j;
	for(i=0;i<NUM_ITT;i++)
	{
		L[i]=(char*)malloc(numchars/2);
		R[i]=(char*)malloc(numchars/2);
	}

	for(i=0;i<numchars/2;i++)
	{
		L[0][i]=text[i];
		R[0][i]=text[numchars/2+i];
	}
	
	
	for(i=1;i<NUM_ITT;i++)
	{
		for(j=0;j<numchars/2;j++)
		{
			L[i][j]=R[i-1][j];
			R[i][j]=L[i-1][j]^this->feis_func(R[i-1][j],i,j);
		}
	}

	for(i=0;i<numchars/2;i++)
	{
		otext[i]=L[NUM_ITT-1][i];
		otext[numchars/2+i]=R[NUM_ITT-1][i];
	}

	otext[size-1]=0;

}

void EncryptionHelper::feis_decode(char* text,char* otext,int size)
{
	char* retval;
	char* L[NUM_ITT];
	char* R[NUM_ITT];
	int numchars;
	numchars=size;
	


	int i,j;
	for(i=0;i<NUM_ITT;i++)
	{
		L[i]=(char*)malloc(numchars/2);
		R[i]=(char*)malloc(numchars/2);
	}

	for(i=0;i<numchars/2;i++)
	{
		L[0][i]=text[i];
		R[0][i]=text[numchars/2+i];
	}
	
	for(i=1;i<NUM_ITT;i++)
	{
		for(j=0;j<numchars/2;j++)
		{
			R[i][j]=L[i-1][j];
			L[i][j]=R[i-1][j]^feis_func(R[i][j],NUM_ITT-i,j);
		}
	}

	for(i=0;i<numchars/2;i++)
	{
		otext[i]=L[NUM_ITT-1][i];
		otext[numchars/2+i]=R[NUM_ITT-1][i];
	}

	otext[size-1]=0;

}

unsigned int EncryptionHelper::gen_nonce()
{
	unsigned int new_nonce;
	new_nonce=rand()%UINT_MAX;
	if(nonce.size()==0)nonce.push_back(new_nonce);
	else
	{
		for(int i=0;i<nonce.size();i++)
		{
			if(nonce[i]==new_nonce)
			{
				new_nonce=rand()%UINT_MAX;
				i=0;
			}
		}
		nonce.push_back(new_nonce);
	}
	return new_nonce;
}

