/*
 * =====================================================================================
 *
 *       Filename:  abejas_hw9_task2.c
 *       	Usage:  ./abejas_hw9_task2.c
 *    Description: Ozonemixing ratio 
 *
 *        Version:  1.0
 *        Created:  04/04/2017 04:37:59 PM
 *       Compiler:  gcc -Wall -Werror
 *         Author:  Braxton Greenwell (), braxtongreenwell@mail.weber.edu
 * =====================================================================================
 */
#include <stdio.h>		/* For Standard I/O */
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define N 4
/* Function Prototypes */
void Usage(void);
void ReadFile(char* fName, float sum[], float x[], float[]);
void Summation(float* summate, float sum[]);

/* Main Program */
int main(int argc, char *argv[])
{
	float x[N];
	float y[N];
	float xy[N];
	float x2[N];
	float sum[10];
	float m, b;

	int sumi;
	float sumx = 0, sumy = 0, sumxy = 0, sumx2 = 0;
	
	if(argc != 2)
	{
		Usage();
	}

	ReadFile(argv[1], sum, x, y);



	return 0;
}


/* Function Defenitions */
void Usage(void)
{

	return;
}
void ReadFile(char* fName, int data[])
{
	FILE *inFile;
	inFile = fopen(fName, "r");
	int
	return;
}
void Summation(float* summate, float sum[])
{

	return;
}
