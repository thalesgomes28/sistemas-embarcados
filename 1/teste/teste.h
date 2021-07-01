#ifndef TESTE_H
#define TESTE_H

float * alloc_vector(int N);

void free_vector(float *v);

int un_sin_gen(float *v, float M, float phi, int N);

int save_vector(float *v, int N,char *file);

#endif

