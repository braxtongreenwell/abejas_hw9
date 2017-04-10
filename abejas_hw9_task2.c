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
void ReadFile(char* fName, float summ[], float x[], float y[]);
void Summation(float* summate, float summ[]);

/* Main Program */
int main(int argc, char *argv[])
{
	float x[N];
	float y[N];
	float xy[N];
	float x2[N];
	float summ[10];
	float m, b;

	int sumi;

	float sumx = 0, sumy = 0, sumxy = 0, sumx2 = 0;

	if(argc != 2)
	{
		Usage();
	}

	else
	{


		ReadFile(argv[1], summ, x, y);




		for(int i = 0; i < N; i++)
		{
			xy[i] = (x[i] * y[i]);
			x2[i] = (x[i] * y[i]);
		}
		
		printf("Range of altitudes in km:\n %.2f to %.2f\n\n", x[0], x[N-1]);
		
		Summation(&sumx, x);
		Summation(&sumy, y);
		Summation(&sumxy, xy);
		Summation(&sumx2, x2);

		sumi = (sumx * sumx);
		
		//m = 0.37, b = -4.6
		
		m = (((sumx * sumy) - (N * sumxy)) / (sumi - (N * sumx2)));
		b = (((sumx * sumxy) - (sumx2 * sumy)) / (sumi - (N * sumx2)));

		printf("Linear model: \n");
		printf("Ozone-mix-ratio = %.2f altitude + %.2f\n", m, b);
	}

	return 0;
}


/* Function Defenitions */
void Usage(void)
{
	printf("Usage ./task2 <dataFile>\n");
	exit(1);

	return;
}
void ReadFile(char* fName, float summ[], float x[], float y[])
{
	int i, a, b;
	int count = 0;
	FILE *inFile;

	inFile = fopen(fName, "r");

	if(inFile == NULL)
	{
		Usage();
		exit(2);
	}
	else
	{


		while(fscanf(inFile, "%f", &summ[i]) != EOF)
		{
			if(count == 0)
			{
				x[a] = summ[i];
				a++;
				count = 1;
			}
			else
			{
				y[b] = summ[i];
				b++;
				count = 0;
			}
			i++;
		}
		return;
	}
}
void Summation(float* summate, float summ[])
{
	for(int i = 0; i < N; i++)
	{
		(*summate) += summ[i];
	}
	return;
}
