#include <stdio.h>

//prot�tipos das fun��es
int fcopy (char nomeArqDestino[], char nomeArqOrigem[]);

//main
void main ()
{
	if (fcopy ("novo.c", "arquivos6.c"))
	{
		printf ("\n\nArquivo novo.c gerado com sucesso!\n\n");
	}
	else
	{
		printf ("\n\nErro na gera��o do arquivo novo.c!\n\n");
	}
	
	if (fcopy ("novo2.c", "arquivos7.c"))
	{
		printf ("\n\nArquivo novo2.c gerado com sucesso!\n\n");
	}
	else
	{
		printf ("\n\nErro na gera��o do arquivo novo2.c!\n\n");
	}
}

//implementa��o das fun��es
int fcopy (char nomeArqDestino[], char nomeArqOrigem[])
{
	//declara��o de vari�veis
	FILE *arqO, *arqD;	
	char ch;
	
	//abrindo os arquivos
	arqD = fopen (nomeArqDestino, "w");
	arqO = fopen (nomeArqOrigem, "r");
	
	//verificando se os arquivos foram abertos
	//if ((arqD != NULL) && (arqO != NULL))
	if (arqD && arqO)
	{
		//manipulando os arquivos
		while (fscanf(arqO,"%c", &ch) != EOF)  //EOF - enf of file
		{
			fprintf (arqD, "%c", ch);
		}
		
		//fechando os arquivos
		fclose (arqO);
		fclose (arqD);
		
		return 1;
	}
	else
	{
		//fechando os arquivos, uma vez que um deles pode ainda estar aberto
		fclose (arqO);
		fclose (arqD);
		
		return 0;
	}	
}
