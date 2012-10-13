/*********************************************************/
/*	Filename: feistel.h		Author: Keith Lee			 */
/*	Date: 10/11/12										 */
/*	Desc:  for EECE412 VPN assignment encryption block	 */
/*********************************************************/
#include<iostream>
#include<string>
#include<limits.h>

#define NUM_ITT 12

using namespace std;

//Predefined number of itterations

//Seed for keyset
string password="PASSWORD";

long keyset[NUM_ITT];

//Sets Password
//Requires: text!=null
//Modifies: password
void setpass(string text)
{
	password=text;
}

//Populates keyset.  Random simple mathematical function
//Requires: password!=null
//Modifies: keyset[o..NUM_ITT]
void make_keys()
{
	for(int i=0;i<NUM_ITT;i++)
	{
		keyset[i]=(long)(password[i%(password.size()-1)]*password[((32*i)+5)%(password.size()-1)]+(i+1)*password[(2*i+1)%(password.size()-1)]);
	}
}

//Round function for feistel alg
//Requires: in!=0, 
//			itt<NUM_ITT
//Returns: char to be XORed within alg
char func(char in, int itt, int index)
{
	return ((2*(in*keyset[itt]/(index+1)))%UCHAR_MAX)+1;
}

//Encryption alg
//Requires:	size%2!=0,
//			text!=null
//			text[i]!=0 for i in 0 to size-1;
//			password!=null
//Returns:	encoded string;
char* fesitel_encode(char* text, int size)
{
	make_keys();
	char* retval;
	char* L[NUM_ITT];
	char* R[NUM_ITT];
	int numchars;
	
	
	numchars=size;


	retval=(char*)malloc(size);

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
			R[i][j]=L[i-1][j]^func(R[i-1][j],i,j);
		}
	}

	for(i=0;i<numchars/2;i++)
	{
		retval[i]=L[NUM_ITT-1][i];
		retval[numchars/2+i]=R[NUM_ITT-1][i];
	}

	retval[size-1]=0;

	return retval;
}

//Decryption alg
//Requires:	size%2!=0,
//			text!=null
//			text[i]!=0 for i in 0 to size-1;
//			password!=null
//Returns:	decoded string;
char* fesitel_decode(char* text, int size)
{
	make_keys();
	char* retval;
	char* L[NUM_ITT];
	char* R[NUM_ITT];
	int numchars;
	
	if(size%2==0)numchars=size;
	else numchars=size-1;
	
	retval=(char*)malloc(size);

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
			L[i][j]=R[i-1][j]^func(R[i][j],NUM_ITT-i,j);
		}
	}

	for(i=0;i<numchars/2;i++)
	{
		retval[i]=L[NUM_ITT-1][i];
		retval[numchars/2+i]=R[NUM_ITT-1][i];
	}

	retval[size-1]=0;

	return retval;
}
