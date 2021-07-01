#include "teste.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float * alloc_vector(int N)
{
	float *v;

	v = malloc(N*sizeof(float));

	return v;
}

void free_vector(float *v)
{
	if (v != NULL) 
		free(v);

	return;
}

int un_sin_gen(float *v, float M, float phi, int N)
{
	int n;
	float w;

	if (v==NULL)
		return -1;

	for(n=0; n<N; n++) {
		w = phi + 2*M_PI*n/M;
		v[n] = sinf(w);
	}

	return 0;
}

int save_vector(float *v, int N, char *file)
{
	int n;
	FILE *f;

	f = fopen(file,"w");
	if (f==NULL)
		return -1;
	
	for(n=0; n<N; n++)
		fprintf(f,"%d\t%f\n",n,v[n]);

	fclose(f);
	return 0;
}

