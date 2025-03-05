/* FAETERJ-Rio
   Fundamentos de Programa��o - FPR - Manh�
   Professor Leonardo Vianna
   Aula de 29/05/2024
   
   Lista de Exerc�cios IV (Arquivos):
   
   Quest�o 02:
   Desenvolver uma fun��o que, dado um arquivo texto, verifique o 
   n�mero de vezes que um determinado caracter aparece no arquivo.
*/

//importa��o de bibliotecas
#include <stdio.h>

//prot�tipos das fun��es
int numOcorrencias (char nomeArq[], char caracter);

//main
void main ()
{
	//declara��o de vari�veis
	char nome[30];
	int resposta;
	char c;
	
	//obtendo o nome do arquivo
	printf ("Nome do arquivo: ");
	fflush (stdin);
	gets (nome);
	
	//obtendo o caracter a ser buscado
	printf ("Caracter a ser buscado: ");
	fflush (stdin);
	scanf ("%c", &c);
	
	//chamando a fun��o
	resposta = numOcorrencias (nome, c);
	
	//exibindo o resultado
	if (resposta == -1)
	{
		printf ("\nO arquivo %s nao foi aberto!\n", nome);
	}
	else
	{
		printf ("\nForam encontrados %d ocorrencias do caracter %c no arquivo %s.\n", resposta, c, nome);
	}
}

//implementa��o das fun��es
int numOcorrencias (char nomeArq[], char caracter)
{
	//declara��o de vari�veis
	FILE* arq;   //passo 1: declarar a vari�vel FILE*
	char ch;
	int cont = 0;
	
	//passo 2: associar a vari�vel FILE* ao caminho do arquivo em disco
	arq = fopen (nomeArq, "r");  // r - read
	
	//passo 3: verificar se o arquivo foi aberto
	//if (arq == NULL)
	if (!arq)
	{
		return -1;
	}
	else
	{
		//passo 4: manipula��o do arquivo
		while (fscanf (arq, "%c", &ch) != EOF)   //EOF - enf of file
		{
			//verificando se o caracter lido � aquele sendo buscado
			if (ch == caracter)
			{
				cont++;
			}
		}
		
		//passo 5: fechando o arquivo
		fclose (arq);
		
		return cont;
	}
}
