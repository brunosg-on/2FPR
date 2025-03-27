#include <stdio.h>
int lerArquivo (char nomeArquivo[])
{
	//declaração de variáveis
	FILE *arq;	//Passo 1: criar uma variável para referenciar o arquivo
	char ch;
	
	//Passo 2: abrindo o arquivo, após associá-lo a um caminho
	arq = fopen (nomeArquivo, "r");
	
	//verificando se o arquivo foi aberto
	if (arq != NULL)
	{
		//Passo 3: manipulando o arquivo
		while (fscanf(arq,"%c", &ch) != EOF)  //EOF - enf of file
		{
			printf ("%c", ch);
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
void main ()
{
	
}
