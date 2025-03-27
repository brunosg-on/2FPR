//importação de bibliotecas
#include <stdio.h>

//main
void main ()
{
	//declaração de variáveis
	int i;
	FILE *arq;	//Passo 1: criar uma variável para referenciar o arquivo

	//Passo 2: abrindo o arquivo, após associá-lo a um caminho
	arq = fopen ("numeros.txt", "w");
	
	//verificando se o arquivo foi aberto
	if (arq != NULL)
	{
		for (i=1;i<=100;i++)
		{
			//Passo 3: manipulando o arquivo
			fprintf (arq, "%d\n", i);
		}
		
		//Passo 4: fechando o arquivo
		fclose (arq);
		
		printf ("\n\nArquivo gerado com sucesso!\n\n");
	}
	else
	{
		printf ("\n\nErro na abertura do arquivo!\n");
	}
}
