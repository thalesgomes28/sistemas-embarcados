
#include "lib_vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

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

/*
 * Função que salva o vetor 'v' no arquivo texto cujo nome é definido pela 
 * string 'file'. Escreve, na primeira linha do arquivo, uma string de
 * identificação seguida pelo número de elementos do vetor:
 * '#tamanho	X'
 * Retorna -1 em caso de erro.
 */
int salva_vetor(struct vetor *v, char *file)

{

	int n;
	FILE *pe;
	pe = fopen(file, "w");
	if (pe == NULL)
		return -1;

	for (n = 1; n < v->N; n++)
	{
		// * '#tamanho	X'
		if (n == 1)
		{
			fprintf(pe, "#Tamanho\t%d\n", v->N);
		}

		fprintf(pe, "%f\n", v->vet[n]);
	}

	fclose(pe);
	return 0;
}

/*
 * Função que lê o vetor do arquivo texto cujo nome é definido pela 
 * string 'file'. O tamanho do vetor é obtido da primeira linha do arquivo.
 * Retorna um ponteiro 'NULL' em caso de erro.
 */
struct vetor *le_vetor(char *file)
{
	FILE *pe;
	int num;
	struct vetor *v;

	char str[8];
	pe = fopen(file, "r");
	if (pe == NULL)
		return NULL;

	//fscanf(pe, "%s:%d\n", str, &num);
	fscanf(pe, "%s\t%d\n", str, &num);

	//v = malloc(num);
	v = aloca_vetor(num);

	for (int i = 0; i < v->N; i++)
	{
		fscanf(pe, "%f\n", &v->vet[i]);
	}

	printf("Primeira linha: %s\t%d\n ", str, num);

	printf("Valor na posição 0 do arquivo %s : %lf\n ", file, v->vet[0]);

	fclose(pe);
	return v;
}

/*
 * FUNÇÕES DE ESCRITA BINÁRIA
 */
struct vetor *bWrite_vetor(struct vetor *v, char *file)
{
	//FILE *pe;
	int fd, nb, r;
	void *p;

	

	//pe = fopen(file, "w");
	
	nb = v->N * sizeof(tipo);
	p = (void *)v->vet; // numero de bytes
	fd = creat(file, S_IRUSR| S_IWUSR ); //teste de nova função
	r = write(fd, p, nb);
	while (r < nb)
	{
		nb -= r;
		p += r;
		r = write(fd, p, nb);
		printf("bytes escritos: %d", r);
	};

	return 0;
}
	
struct vetor *bRead_vetor(struct vetor *v, char *file)
{
	//FILE *pe;
	int fd, nb, r;
	void *p;

	

	
	fd = open(file, O_WRONLY | O_CREAT);
	nb = v->N * sizeof(tipo);
	p = (void *)v->vet; // numero de bytes
	
	r = read(fd, p, nb);
	while (r < nb)
	{
		nb -= r;
		p += r;
		r = write(fd, p, nb);
		printf("bytes lidos: %d", r);
	};

	return r;
}
 