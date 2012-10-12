#include<iostream>
#include<math.h>
#include<vector>
#include<limits.h>

#define NUM_ITT 12

#define BLOCK_S 32

#define SET_S BLOCK_S/2

char keyset[NUM_ITT][SET_S];

char func(char byte, char key)
{
	
	return (byte+key)*2 - byte;
	
}

char* feistel_encode(char* plain)
{
	char L[NUM_ITT][SET_S];
	char R[NUM_ITT][SET_S];
	char cypher[BLOCK_S];
	int i,j;
	for(i=0;i<SET_S;i++)
	{
		L[0][i]=plain[i];
		R[0][i]=plain[SET_S+i];
	}

	for(i=1;i<NUM_ITT;i++)
	{
		for(j=0;j<SET_S;j++)
		{
			L[i][j]=R[i-1][j];
			R[i][j]=L[i-1][j]^func(R[i-1][j],keyset[i][j]);
		}
	}
	for(i=0;i<SET_S;i++)
	{
		cypher[i]=L[NUM_ITT-1][i];
		cypher[SET_S+i]=R[NUM_ITT-1][i];
	}
	return cypher;
}

char* feistel_decode(char* cypher)
{
	char plain[BLOCK_S];
	char L[NUM_ITT][SET_S];
	char R[NUM_ITT][SET_S];
	int i,j;
	for(i=0;i<SET_S;i++)
	{
		L[0][i]=cypher[i];
		R[0][i]=cypher[SET_S+i];
	}

	for(i=1;i<NUM_ITT;i++)
	{
		for(j=0;j<SET_S;j++)
		{
			R[i][j]=L[i-1][j];
			L[i][j]=R[i-1][j]^func(R[i][j],keyset[NUM_ITT-i][j]);
		}
	}

	for(i=0;i<SET_S;i++)
	{
		plain[i]=L[NUM_ITT-1][i];
		plain[SET_S+i]=R[NUM_ITT-1][i];
	}
	return plain;
}

int main()
{
	int i,j;
	for(i=0;i<SET_S;i++)
	{
		for(j=0;j<NUM_ITT;j++)
		{
			keyset[i][j]=149+i;
		}
	}

	char* input="This line of text by Keith Lee to test FE";
	char* output;
	char plaintext[32];
	char cyphertext[32];

	for(i=0;i<32;i++)
	{
		plaintext[i]=input[i];
	}
	for(i=0;i<32;i++)
	{
		printf("%c",plaintext[i]);
	}
	printf("\n");


	output=feistel_encode(plaintext);


	for(i=0;i<32;i++)
	{
		cyphertext[i]=output[i];
	}
	for(i=0;i<32;i++)
	{
		printf("%c",cyphertext[i]);
	}
	printf("\n");


	output=feistel_decode(cyphertext);


	for(i=0;i<32;i++)
	{
		cyphertext[i]=output[i];
	}
	for(i=0;i<32;i++)
	{
		printf("%c",cyphertext[i]);
	}
	printf("\n");

	return 0;
}



	
