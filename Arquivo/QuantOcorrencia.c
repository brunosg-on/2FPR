#include <stdio.h>

//protótipos das funções
int numOcorrencias (char nomeArq[], int numero);

//main
void main ()
{
	//declaração de variáveis
	int quant;
	
	//chamada 1
	quant = numOcorrencias ("numeros.txt", 4);
	printf ("Resposta: %d\n\n", quant);

	//chamada 2
	quant = numOcorrencias ("numeros.txt", 3);
	printf ("Resposta: %d\n\n", quant);
	
	//chamada 3
	quant = numOcorrencias ("numeros1.txt", 4);
	printf ("Resposta: %d\n\n", quant);
}

//implementação das funções
int numOcorrencias (char nomeArq[], int numero)
{
	//declaração de variáveis
	FILE *arq;	
	int valor, cont = 0;
	
	//abrindo o arquivo
	arq = fopen (nomeArq, "r");
	
	//verificando se o arquivo foi aberto
	if (arq)
	{
		//manipulando o arquivo
		while (fscanf(arq,"%d", &valor) != EOF)  //EOF - enf of file
		{
			//verificando se o valor lido é igual àquele sendo buscado
			if (valor == numero)
			{
				cont++;
			}
		}
		
		//fechando o arquivo
		fclose (arq);

		return cont;
	}
	else
	{
		return -1;
	}	
}
