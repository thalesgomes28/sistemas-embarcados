/*
 * Exemplo de criação de um processo filho, seguido pela execução dos programas
 * em 'pai.c' e 'filho.c', com conexão de saída e entrada padrão.
 *

 */
#include <unistd.h>

int main(int argc, char **argv)
{
	int p[2];

	pipe(p);
	if (fork() == 0) {
		/* processo filho */
		close(p[1]);
		dup2(p[0],STDIN_FILENO);
		execl("./filho","./filho",NULL);

	} else {

		/* processo pai */
		close(p[0]);
		dup2(p[1],STDOUT_FILENO);
		execl("./pai","./pai","argumento",NULL);
	}
  	/* nunca acontece */
	return 0;
}

