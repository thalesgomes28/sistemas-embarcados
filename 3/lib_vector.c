
#include "lib_vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct vetor *aloca_vetor(int N)
{
	struct vetor *v;

	v = malloc(sizeof(struct vetor));
	if (v == NULL)
	{
		printf("Falha na alocacao de memoria.\n");
		return NULL;
	}

	v->vet = malloc(N * sizeof(tipo));
	if (v->vet == NULL)
	{
		free(v);
		printf("Falha na alocacao de memoria.\n");
		return NULL;
	}

	v->N = N;
	v->scale = 1.0;
	v->fa = 1.0;

	return v;
}

void desaloca_vetor(struct vetor *v)
{
	if (v != NULL)
	{
		free(v->vet);
		free(v);
	}
	return;
}

int aleatorio(struct vetor *v)
{
	int n;
	tipo x;

	if (v == NULL)
		return -1;

	for (n = 0; n < v->N; n++)
	{
		x = (tipo)rand();
		v->vet[n] = 2 * (x / RAND_MAX - 0.5);
	}
	return 0;
}

int soma(struct vetor *v1, struct vetor *v2, struct vetor *v3)
{
	int n;
	
	if (v1 == NULL || v2 == NULL)
		return -1;
	for (n = 0; n < v1->N; n++)
	{
		v3->vet[n] = v1->vet[n] + v2->vet[n];
	}
	return 0;
}

tipo media(struct vetor *v)
{
	int n;

	if (v == NULL)
		return -1;

	tipo x = v->vet[0];

	for (n = 1; n < v->N; n++)
	{

		x = x + v->vet[n];
	}

	return x;
}
