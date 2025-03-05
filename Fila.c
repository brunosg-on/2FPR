/* FAETERJ-Rio
   Fundamentos de Programa��o - FPR - Manh�
   Professor Leonardo Vianna
   Data: 12/06/2024
   
   Filas (encadeadas)
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//defini��o de tipos
typedef struct No {
	int valor;
	struct No *prox;
} TNo;

typedef TNo* TLista;

//prot�tipos das fun��es
int enfilar (TLista *F, TLista *U, int numero);
int desenfilar (TLista *F, TLista *U, int *numero);
int primeiro (TLista F, int *p);

int menu ();

//main
void main ()
{
	//declara��o de vari�veis
	TLista F = NULL, U = NULL;  //representando a fila inicialmente vazia
	int num, op;	
	
	do
	{
		system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usu�rio
		op = menu ();
		
		//verificando a op��o escolhida
		switch (op)
		{
			//Enfilar
			case 1: printf ("\nEntre com o valor a ser inserido na fila: ");
			        scanf ("%d", &num);
			        
			        //chamando a fun��o
			        if (enfilar (&F, &U, num) == 1)   //ou apenas: if (enfilar (&F, &U, num))			        
			        {
			        	printf ("\n\tInsercao realizada com sucesso!");
					}
					else
					{
						printf ("\n\tERRO: insercao nao realizada!");
					}
					break;

			//Desenfilar
			case 2: //chamando a fun��o
			        if (desenfilar (&F, &U, &num))
			        {
			        	printf ("\n\tO valor %d foi removido da fila!", num);
					}
					else
					{
						printf ("\n\tERRO: Fila vazia!");
					}
					break;

			//Primeiro
			case 3: //chamando a fun��o
			        if (primeiro (F, &num))
			        {
			        	printf ("\n\tPrimeiro elemento da fila: %d", num);
					}
					else
					{
						printf ("\n\tERRO: Fila vazia!");
					}
					break;
					
			//Sa�da
			case 4: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}
	while (op != 4);
}

//implementa��o das fun��es
int enfilar (TLista *F, TLista *U, int numero)
{
	//declara��o de vari�veis
	TLista aux;
	
	//Passo 1: alocar mem�ria para o novo elemento
	aux = (TLista) malloc (sizeof(TNo));   //malloc - memory allocation
	
	//verificando se houve erro na aloca��o
	if (!aux)
	{
		return 0;
	}
	else
	{
		//Passo 2: armazenando 'numero' na posi��o rec�m-alocada
		aux->valor = numero;
		
		//fazendo o campo 'prox' do novo n� apontar para NULL (uma vez que ser� o �ltim da fila)
		aux->prox  = NULL;
		
		//verificando se existem elementos na fila
		if (*F)  //poderia tamb�m ser:   if (*U)
		{
			//fazendo o campos 'prox' do �ltimo da fila apontar para o novo n�
			(*U)->prox = aux;
		}
		else
		{
			//atualizando o 'F', de forma a apontar para o novo n�
			*F = aux;
		}
		
		//atualizando 'U'
		*U = aux;   //ou:   *U = (*U)->prox;
		
		return 1;
	}
}

int desenfilar (TLista *F, TLista *U, int *numero)
{
	//declara��o de vari�veis
	TLista aux;
	
	//verificando se a fila possui elementos
	if (*F)
	{
		//aux guardando o endere�o do n� que ser� removido
		aux = *F;   
			
		//fazendo *F apontar para o "antigo segundo n�"
		*F = aux->prox;       //ou   *F = (*F)->prox;
		
		//verificando se a fila se tornou vazia
		if (!(*F))
		{
			*U = NULL;
		}	
		
		//armazenando no par�metro 'numero' o valor que era o primeiro da fila
		*numero = aux->valor;
		
		//liberando a mem�ria do n� a ser removido
		free (aux);			
		
		return 1;
	} 
	else
	{
		return 0;
	}
}

int primeiro (TLista F, int *p)
{
	//verificando se a fila possui elementos
	if (F)
	{
		//armazenando em 'p' o primeiro valor da fila
		*p = F->valor;
		
		return 1;
	}
	else
	{
		return 0;
	}
}

int menu ()
{
	//declara��o de vari�veis
	int opcao;
	
	//exibindo o meu ao usu�rio
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Enfilar\n");
	printf ("(2) Desenfilar\n");
	printf ("(3) Primeiro\n");
	printf ("(4) Sair\n\n");
	
	//lendo a op��o do usu�rio
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a op��o escolhida
	return opcao;
}
