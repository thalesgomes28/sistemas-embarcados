/*
 * Exemplo de leitura da entrada padrão. 
 */
#include <stdio.h>

int main(int argc, char **argv)
{
	float aux, value = 0;
	int count = -1;
	float media;

	//scanf("%f\n", &value);

	do {
		//printf("digite um numero posição: %d: ", count);
		aux = aux + value;
		count++;		
		scanf("%f", &value);
	
	}while (value != -1);

	//soma dos valores obtidos
	/* for (int n = 0; n < sizeof(new_v); n++)
	{
		aux = aux + new_v[n];
	} */

	media = aux / count;


	printf("%d\n", count);

	printf("%f\n", media);

	return 0;
}

/* int main(int argc, char **argv)
{
	char str1[20], str2[20];

	scanf("%s:%s\n",str1,str2);
	printf("%s|%s%s\n",argv[0],str1,str2);

	return 0;
}
 */