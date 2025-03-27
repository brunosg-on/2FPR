//importa��o de bibliotecas
#include <stdio.h>

//prot�tipos das fun��es
int numLetrasArquivo (char nomeArq[]);

//main
void main ()
{
	//declara��o de vari�veis
	char nomeArquivo[30];
	int quantidade;
	
	//lendo o nome do arquivo
	printf ("Nome do arquivo: ");
	fflush (stdin);
	gets (nomeArquivo);
	
	//chamando a fun��o
	quantidade = numLetrasArquivo (nomeArquivo);
	
	//exibindo o resultado
	if (quantidade != -1)
	{
		printf ("\n\nForam encontradas %d letras no arquivo %s.", quantidade, nomeArquivo);
	}
	else
	{
		printf ("\n\nHouve erro na abertura do arquivo %s.", nomeArquivo);
	}
}

//implementa��o das fun��es
int numLetrasArquivo (char nomeArq[])
{
	//declara��o de vari�veis
	FILE* arq;
	int cont = 0;
	char caracter;
	
	//abrindo o arquivo e associando 'arq' a 'nomeArq'
	arq = fopen (nomeArq, "r");		//modo: r - read  /  w - write  /  a - append
	
	//testando se houve erro na abertura do arquivo
	if (arq == NULL)
	{
		return -1;
	}
	else
	{
		//lendo caracteres enquanto n�o chegar ao final do arquivo
		while (fscanf(arq, "%c", &caracter) != EOF)   //end of file
		{
			//colocando o caracter em mai�sculo
			caracter = toupper (caracter);
			
			//verificando se o caracter lido � uma letra
			if ((caracter >= 'A') && (caracter <= 'Z'))
			{
				cont++;
			}
		}
		
		//fechando o arquivo
		fclose (arq);
		
		//retornando o resultado
		return cont;
	}
}
