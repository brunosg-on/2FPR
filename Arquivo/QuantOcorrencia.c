#include <stdio.h>

//prot�tipos das fun��es
int numOcorrencias (char nomeArq[], int numero);

//main
void main ()
{
	//declara��o de vari�veis
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

//implementa��o das fun��es
int numOcorrencias (char nomeArq[], int numero)
{
	//declara��o de vari�veis
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
			//verificando se o valor lido � igual �quele sendo buscado
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
