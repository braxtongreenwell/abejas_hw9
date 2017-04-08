/*
 * =====================================================================================
 *
 *       Filename:  abejas_hw9_task1.c
 *       	Usage:  ./abejas_hw9_task1.c
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/04/2017 04:37:38 PM
 *       Compiler:  gcc -Wall -Werror
 *         Author:  Braxton Greenwell (), braxtongreenwell@mail.weber.edu
 * =====================================================================================
 */
#include <stdio.h>		/* For Standard I/O */
#include <stdlib.h>

#define SIZE 81
	


/* Function Prototypes */


void ReadFile(FILE *file1, float num[]);
	float data[SIZE];
/* Main Program */
int main(int argc, char *argv[])
{
	FILE *infile;
	infile = fopen(argv[1],"r");
	
	if(infile == NULL)
	{
		printf("The file was not successfully read.\n");
		exit(1);
	}
	printf("The dat file %s was successfully read.\n\n", argv[1]);

	ReadFile(infile, data);


	
	fclose(infile);
	return 0;
}


/* Function Defenitions */

void ReadFile(FILE *file1, float num[])
{
	int count = 0;
	while(fscanf(file1, "%f" , &num[count]) != EOF)
	{
		printf("scanning %f\n", num[count]);
	count++;
	}

	return;
}

