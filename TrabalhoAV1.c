#include <stdio.h>

void ExibirVetor(int vet[], int tam)
{
	int i;
	printf("\n\n");
	for(i=0; i<tam; i++)
	{
		printf("%d ", vet[i]);
	}
	printf("\n\n");
}

void PreecherVetorAleatoriamente(int vet[], int tam, int max)
{
	int i;
	srand(time(NULL));
	
	for(i=0; i<tam; i++)
	{
		vet[i] = rand() % max+1;
	}	
}

void SelectionSort(int vet[], int tam)
{
	int i, j, min, aux;
	
	for(i=0;i<tam-1;i++)
	{
		min = i;
		for(j=i+1;j<tam;j++)
		{
			if(vet[j]< vet[min])
			{
				min = j;
			}
		}
		if(i!=min)
		{
			aux = vet[i];
			vet[i] = vet[min];
			vet[min] = aux;
		}
	}
}

void main ()
{
	int tam, max;
	printf("Qual o tamanho do vetor? ");
	scanf("%d", &tam);
	
	printf("Qual o valor maximo do vetor? ");
	scanf("%d", &max);
	int vet[tam];
	PreecherVetorAleatoriamente(vet, tam, max);
	printf("Antes do Selection Sort:");
	
	ExibirVetor(vet, tam);
	SelectionSort(vet, tam);
	
	printf("Depois do Selection Sort:");
	
	ExibirVetor(vet, tam);
	

}

