//importa��o de bibliotecas
#include <stdio.h>

//prot�tipos das fun��es
int escreverArquivo (char nomeArquivo[], int n);

//main
void main ()
{
	escreverArquivo ("teste1.txt", 300);
	escreverArquivo ("teste2.txt", 500);
	escreverArquivo ("teste1.txt", 20);
}

//implementa��o das fun��es
int escreverArquivo (char nomeArquivo[], int n)
{
	//declara��o de vari�veis
	int i;
	FILE *arq;	//Passo 1: criar uma vari�vel para referenciar o arquivo

	//Passo 2: abrindo o arquivo, ap�s associ�-lo a um caminho
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
