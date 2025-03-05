/* FAETERJ-Rio
   Fundamentos de Programa��o - FPR - Manh�
   Professor Leonardo Vianna
   Data: 12/06/2024
   
   Pilhas (encadeadas)
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
int empilhar (TLista *P, int numero);
int desempilhar (TLista *P, int *numero);
int topo (TLista P, int *t);

int menu ();

//main
void main ()
{
	//declara��o de vari�veis
	TLista P = NULL;  //representando a pilha inicialmente vazia
	int num, op;	
	
	do
	{
		system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usu�rio
		op = menu ();
		
		//verificando a op��o escolhida
		switch (op)
		{
			//Empilhar
			case 1: printf ("\nEntre com o valor a ser inserido na pilha: ");
			        scanf ("%d", &num);
			        
			        //chamando a fun��o
			        if (empilhar (&P, num) == 1)   //ou apenas: if (empilhar (&P, num))			        
			        {
			        	printf ("\n\tInsercao realizada com sucesso!");
					}
					else
					{
						printf ("\n\tERRO: insercao nao realizada!");
					}
					break;

			//Desempilhar
			case 2: //chamando a fun��o
			        if (desempilhar (&P, &num))
			        {
			        	printf ("\n\tO valor %d foi removido da pilha!", num);
					}
					else
					{
						printf ("\n\tERRO: Pilha vazia!");
					}
					break;

			//Topo
			case 3: //chamando a fun��o
			        if (topo (P, &num))
			        {
			        	printf ("\n\tTopo da pilha: %d", num);
					}
					else
					{
						printf ("\n\tERRO: Pilha vazia!");
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
int empilhar (TLista *P, int numero)
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
		
		//Passo 3: fazer o novo n� apontar para o "antigo primeiro n�"
		aux->prox = *P;
		
		//Passo 4: fazer com que *P aponte para o novo N�
		*P = aux;
		
		return 1;
	}
}

int desempilhar (TLista *P, int *numero)
{
	//declara��o de vari�veis
	TLista aux;
	
	//verificando se a pilha possui elementos
	if (*P)
	{
		//aux guardando o endere�o do n� que ser� removido
		aux = *P;   
			
		//fazendo *P apontar para o "antigo segundo n�"
		*P = aux->prox;       //ou   *P = (*P)->prox;
			
		//armazenando no par�metro 'numero' o valor que estava no topo da pilha
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

int topo (TLista P, int *t)
{
	//verificando se a pilha possui elementos
	if (P)
	{
		//armazenando em 't' o valor que est� no topo da pilha
		*t = P->valor;
		
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
	printf ("(1) Empilhar\n");
	printf ("(2) Desempilhar\n");
	printf ("(3) Topo\n");
	printf ("(4) Sair\n\n");
	
	//lendo a op��o do usu�rio
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a op��o escolhida
	return opcao;
}
