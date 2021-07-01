/*
 * Exemplo de escrita na saída padrão. 

 */
#include <stdio.h>

int main(int argc, char **argv)
{
	int v[] = {15, 54, 89, 1, 6, -1};

	for (int i = 0; i < 6; i++)
	{
		printf("%d\n", v[i]);
	}

	return 0;
}
/* int main(int argc, char **argv)
{
	printf("%s:%s\n",argv[0],argv[1]);

	return 0;
}
 */