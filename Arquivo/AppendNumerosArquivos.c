//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int escreverArquivo (char nomeArquivo[], int n);

//main
void main ()
{
	escreverArquivo ("teste1.txt", 300);
	escreverArquivo ("teste2.txt", 500);
	escreverArquivo ("teste1.txt", 20);
}

//implementação das funções
int escreverArquivo (char nomeArquivo[], int n)
{
	//declaração de variáveis
	int i;
	FILE *arq;	//Passo 1: criar uma variável para referenciar o arquivo

	//Passo 2: abrindo o arquivo, após associá-lo a um caminho
	arq = fopen (nomeArquivo, "a");
	
	//verificando se o arquivo foi aberto
	if (arq != NULL)
	{
		for (i=1;i<=n;i++)
		{
			//Passo 3: manipulando o arquivo
			fprintf (arq, "%d\n", i);
		}
		
		//Passo 4: fechando o arquivo
		fclose (arq);
		
		return 1;
	}
	else
	{
		return 0;
	}	
}
