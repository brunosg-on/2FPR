/* FAETERJ-Rio
   Fundamentos de Programação - FPR - Manhã
   Professor Leonardo Vianna
   Aula de 29/05/2024
   
   Lista de Exercícios IV (Arquivos):
   
   Questão 02:
   Desenvolver uma função que, dado um arquivo texto, verifique o 
   número de vezes que um determinado caracter aparece no arquivo.
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int numOcorrencias (char nomeArq[], char caracter);

//main
void main ()
{
	//declaração de variáveis
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
	
	//chamando a função
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

//implementação das funções
int numOcorrencias (char nomeArq[], char caracter)
{
	//declaração de variáveis
	FILE* arq;   //passo 1: declarar a variável FILE*
	char ch;
	int cont = 0;
	
	//passo 2: associar a variável FILE* ao caminho do arquivo em disco
	arq = fopen (nomeArq, "r");  // r - read
	
	//passo 3: verificar se o arquivo foi aberto
	//if (arq == NULL)
	if (!arq)
	{
		return -1;
	}
	else
	{
		//passo 4: manipulação do arquivo
		while (fscanf (arq, "%c", &ch) != EOF)   //EOF - enf of file
		{
			//verificando se o caracter lido é aquele sendo buscado
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
