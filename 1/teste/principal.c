#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "teste.h"
#define NAMESIZE 64

int main(int argc, char **argv)
{
	int N;
	char filename[NAMESIZE];
	float *v;

	if (argc == 1)
	{
		N = 100;
		printf("Usando N=100\n");
		strcpy(filename, "a.out");
		printf("Usando filename='a.out'\n");
	}
	else
	{
		N = atoi(argv[1]);
		strcpy(filename, argv[2]);
	}

	v = alloc_vector(N);
	if (un_sin_gen(v, 50, 0, N) != 0)
	{
		printf("Falha na alocacao de memoria.\n");
		return -1;
	}

	if (save_vector(v, N, filename) != 0)
	{
		printf("Falha na escrita do arquivo.\n");
		free_vector(v);
		return -1;
	}

	free_vector(v);
	return 0;
}
