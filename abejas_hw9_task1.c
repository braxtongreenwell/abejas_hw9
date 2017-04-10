/*
 * =====================================================================================
 *
 *       Filename:  abejas_hw9_task1.c
 *       	Usage:  ./abejas_hw9_task1.c
 *    Description:  homework for task1
 *
 *        Version:  1.0
 *        Created:  04/04/2017 04:37:38 PM
 *       Compiler:  gcc -Wall -Werror
 *         Author:  Braxton Greenwell () and Adam Lee, braxtongreenwell@mail.weber.edu
 * =====================================================================================
 */
#include <stdio.h>		/* For Standard I/O */
#include <stdlib.h>
#include <string.h>
#define SIZE 12

/* Function Prototypes */
void Usage(char** info);
void ReadFile(char *file1, float num[]);
FILE *OpenCheckFile(char *file2);
void WriteFile(FILE *file3, float num1[]);
float data[SIZE];
char in[SIZE];
char yesno;
char out[SIZE];
FILE *outfile;

/* Main Program */
int main(int argc, char *argv[])
{

	if(argc != 3)
	{
		Usage(argv);
	}
	else
	{	
		strcpy(out, argv[2]);
		strcpy(in, argv[1]);
		ReadFile(in, data);


		OpenCheckFile(out);


		WriteFile(outfile, data);
	} 
	return 0;

}


/* Function Defenitions */
void Usage(char** info)
{
	printf("Usage ./task1 <dataFile> <outFileName>\n");
	exit(1);

	return;
}

void ReadFile(char *file1, float num[])
{
	FILE *infile;
	infile = fopen(file1,"r");
	if(infile == NULL)
	{
		printf("The file was not successfully read.\n");
		exit(1);
	}
	printf("\nThe dat file %s was successfully read.\n\n", file1);
	
	while(fscanf(infile, "%f" , num) != EOF)
	{
		num++;
	}
	fclose(infile);
	return;
}

FILE *OpenCheckFile(char *file2)
{
	outfile = fopen(file2,"w");
	if(file2 != NULL)
	{
		printf("A file by the name %s exists.\n\n", file2); 
	
				
		printf("Do you want to continue and overwrite it\n");
		printf("\nwith the new data? (y or n):");
		scanf("%c", &yesno);	
	}

	return(outfile);
}

void WriteFile(FILE *file3, float num1[])
{
	
	float avg;
	float total;
	if(yesno == 'n' || yesno == 'N')
	{
		printf("The existing file will not be overwritten.\n");
		exit(1);
	}
	if(yesno == 'y' || yesno == 'Y')
	{
		for(int i = 0; i < SIZE; i++)
		{

			fprintf(file3, "\n%.4f\n",num1[i]);
			total += num1[i];

		}
		avg = total/SIZE;
		fprintf(file3,"\n----------\n\n");
		fprintf(file3,"Total: %.4f\n\n", total);
		fprintf(file3,"Avg: %.4f\n\n", avg);

		printf("\nThe file %s has successfully been written as a dat file.\n\n", out);
	}

	
	fclose(outfile);
	return;
}
