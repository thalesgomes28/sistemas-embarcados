/* 
 * Programa de teste das funções do módulo 'lib_vector'.
 *
 * Adriano Cardoso 
 * 01/2021 
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lib_vector.h"

int main(int argc, char **argv)
{
	/* BOA PRÁTICA DE PROGRAMAÇÃO C:
	 * variáveis declaradas no início da função.
	 */
	int N, r;
	struct vetor *v1, *v2, *v3;
	tipo m1, m2, m3;

	/* Etapa 1: verificação dos argumentos de entrada */
	if(argc != 2) {
		printf("Numero de parametros incorretos.\n");
		printf("Utilize:\n\t%s <N>\n\n",argv[0]);
		printf("\t<N> numero de pontos gerados;\n");
		return -1;
	}

	/* Etapa 2: processamento dos argumentos de entrada */
	N = atoi(argv[1]);

	/* Etapa 3: inicializações
	 * BOA PRÁTICA DE PROGRAMAÇÃO:
	 * sempre verifique o retorno das funções. Interrompa o fluxo caso um 
	 * erro grave seja detectado. Reporte o erro encontrado.
	 */
	v1 = aloca_vetor(N);
	if (v1 == NULL) {
		printf("Falha na alocação de v1.\n");
		return -1;
	}

	v2 = aloca_vetor(N);
	if (v2 == NULL) {
		printf("Falha na alocação de v2.\n");
		desaloca_vetor(v1);
		return -1;
	}
	
	v3 = aloca_vetor(N);
	if (v3 == NULL) {
		printf("Falha na alocação de v3.\n");
		desaloca_vetor(v1);
		desaloca_vetor(v2);
		return -1;
	}

	r = aleatorio(v1);
	if (r != 0) {
		printf("Falha na função 'aleatorio()'.\n");
		desaloca_vetor(v1);
		desaloca_vetor(v2);
		desaloca_vetor(v3);
		return -1;
	}

	r = aleatorio(v2);
	if (r != 0) {
		printf("Falha na função 'aleatorio()'.\n");
		desaloca_vetor(v1);
		desaloca_vetor(v2);
		desaloca_vetor(v3);
		return -1;
	}

	soma(v1,v2,v3);
	m1 = media(v1);
	m2 = media(v2);
	m3 = media(v3);

#ifdef TIPO_FLOAT
	printf("m1: %f\tm2: %f\tm3: %f\n",m1,m2,m3);
#elif TIPO_DOUBLE
	printf("m1: %lf\tm2: %lf\tm3: %lf\n",m1,m2,m3);
#else
	printf("m1: %d\tm2: %d\tm3: %d\n",m1,m2,m3);
#endif

	/* Etapa 5: finalização */
	desaloca_vetor(v1);
	desaloca_vetor(v2);
	desaloca_vetor(v3);
	return 0;	
}

