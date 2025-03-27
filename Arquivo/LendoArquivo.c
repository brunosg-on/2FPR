//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int lerArquivo (char nomeArquivo[]);

//main
void main ()
{
	if (lerArquivo ("teste1.txt") == 1)
	{
		printf ("\n\nDados do arquivo teste1.txt lidos com sucesso!\n\n");
	}
	else
	{
		printf ("\n\nErro na abertura do arquivo teste1.txt!\n\n");
	}
	
	if (lerArquivo ("teste.txt") == 1)
	{
		printf ("\n\nDados do arquivo teste.txt lidos com sucesso!\n\n");
	}
	else
	{
		printf ("\n\nErro na abertura do arquivo teste.txt!\n\n");
	}

}

//implementação das funções
int lerArquivo (char nomeArquivo[])
{
	//declaração de variáveis
	FILE *arq;	//Passo 1: criar uma variável para referenciar o arquivo
	int numero;
	
	//Passo 2: abrindo o arquivo, após associá-lo a um caminho
	arq = fopen (nomeArquivo, "r");
	
	//verificando se o arquivo foi aberto
	if (arq != NULL)
	{
		//Passo 3: manipulando o arquivo
		while (fscanf(arq,"%d", &numero) != EOF)  //EOF - enf of file
		{
			printf ("%d\n", numero);
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
