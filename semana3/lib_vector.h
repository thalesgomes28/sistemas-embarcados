
#ifndef LIB_VECTOR_H
#define LIB_VECTOR_H

#define DESCRIPTION_SIZE 30



#ifdef TIPO_FLOAT
	typedef float tipo;
#elif TIPO_DOUBLE
	typedef double tipo;
#else
	typedef int tipo;
#endif
	
/*
 * Estrutura de dados de um vetor.
 * 'N' é o número de elementos do vetor;
 * 'vet' é um ponteiro para o vetor de elementos armazenados.
 * 'scale' e 'fa' são variáveis auxiliares, que podem ser usadas para
 *    armazenamento do fator de escala e frequência de amostragem.
 */
struct vetor {
	int N;
	tipo *vet;
	tipo scale;
	tipo fa;
	char desc[DESCRIPTION_SIZE];
};

/*
 * Aloca memória para um vetor de 'N' elementos do tipo 't_tipo'.
 */
struct vetor * aloca_vetor(int N);

/*
 * Desaloca a memória ocupada pelo vetor 'v'.
 */
void desaloca_vetor(struct vetor *v);

/*
 * Percorre o vetor 'v' e preenche cada um de seus elementos com números
 * aleatórios uniformemente distribuídos entre -1.0 e 1.0. Retorna -1 caso o
 * vetor não esteja alocado.
 */
int aleatorio(struct vetor *v);

/* 
 * Soma os elementos dos vetores 'v1' e 'v2' e armazena o resultado no vetor
 * 'v3'.
 */
int soma(struct vetor *v1, struct vetor *v2, struct vetor *v3);

/* 
 * Calcula e retorna o valor médio dos elementos do vetor.
 */
tipo media(struct vetor *v);


#endif
