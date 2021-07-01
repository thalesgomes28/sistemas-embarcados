#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "teste.h"
#define NAMESIZE 64

int main(int argc, char **argv)
{
	char filename[NAMESIZE];
	
	float *v;

	int N;

	float a, b;

	N = atoi(argv[1]);
	a = atof(argv[2]);
	b = atof(argv[3]);

	printf("\nValor de n:\n%d\n%f\n%f\n", N, a, b);

	if (argc > 1)
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
	if (un_sin_gen(v, a, b, N) != 0)
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
