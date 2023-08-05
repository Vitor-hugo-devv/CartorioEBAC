#include <stdio.h> // biblioteca de comunica��o de usu�rio 
#include <stdlib.h> // biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o 
#include <string.h> // biblioteca respons�vel por cuidar da string

int registro() // Fun�ao respons�vel por cadastrar os usu�rios no sistema
{
	// In�cio cria��o de variaveis/string
	char arquivo[40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	// Final cria��o de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando informa��o do usu�rio
	scanf ("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo,cpf); // Respons�vel por copiar os valores das string
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w"); // Cria o arquivo e o "W" significa escrever (write)
	fprintf(file,cpf); // Salva o valor da vari�vel
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo,"a"); // Abre um arquivo no modo de inclus�o (append)
	fprintf(file, ",");
	fclose(file); // Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); // Coletando informa��o do usu�rio
	scanf("%s", nome); // %s refere-se a string
	
	file = fopen(arquivo,"a"); // Abre um arquivo no modo de inclus�o (append)
	fprintf(file, nome); // Salva o valor da vari�vel 
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo,"a"); // abre um arquivo no modo de inclus�o (append)
	fprintf(file, ",");
	fclose(file); // fecha o arquivo 
	
	printf("Digite o sobrenome a ser cadastrado: "); // Coletando informa��o do usu�rio 
	scanf("%s",sobrenome); // %s refere-se a string
	
	file = fopen(arquivo,"a"); // Abre um arquivo no modo de inclus�o (append)
	fprintf(file, sobrenome); // Salva o valor da vari�vel 
	fclose(file); // Fecha o arquivo 
	
	file = fopen(arquivo,"a"); // Abre um arquivo no modo de inclus�o (append)
	fprintf(file, ",");
	fclose(file); // Fecha o arquivo 
	
	printf("digite cargo a ser cadastrado: "); // Coletando informa��o do ussu�rio 
	scanf("%s",cargo); //  %s refere-se a vari�vel 
	
	file = fopen(arquivo,"a"); // abre um arquivo no modo de inclus�o (append)
	fprintf(file, cargo); // Salva o valor da vari�vel 
	fclose(file); // fecha o arquivo 
	
	system("pause"); // Respons�vel por "travar" a tela 
	
}

int consulta() // Fun��o respos�vel por consultar o usu�rio no sistema 
{
	setlocale(LC_ALL,"Portuguese"); // Definindo a linguagem
	
	//Inicio de cria��o de vari�vel/string
   char cpf[40];
   char conteudo[200];
   // Final de cria��o de variaveis/string
   
   printf("Digite o CPF a ser consultado: "); // Coletando informa��o do usu�rio 
   scanf("%s",cpf); // %s refere-se a string
   
   FILE *file; // Cria o arquivo 
   file = fopen(cpf,"r"); // abre um arquivo no modo leitura 
   
   if (file == NULL)
   {
   		printf ("N�o foi poss�vel abrir o arquivo, n�o localizado!. \n");
   }
   
   while(fgets(conteudo, 200, file) !=NULL)
   {
   		printf ("\nEssas s�o as informa��es do usu�rio: ");
   		printf("%s", conteudo);
   		printf("\n\n");
   }
   
   system("pause"); // Respos�vel por travar a tela 
   
}


int deletar() // Fun��o respos�vel por deletar o usu�rio do sistema
{
	// inicio de cria��o de vari�vel/string
	char cpf[40];
	// Final de cria��o de variaveis/string
    
    printf("Digite o cpf do usu�rio a ser deletado: "); // Coletando indroma��o do usu�rio
    scanf ("%s",cpf); // %s refere-se a string
    
    remove (cpf); // Respons�vel por deletar o usuario 
    
    FILE *file; // Cria o arquivo 
    file = fopen (cpf, "r"); // abre o arquivo no modo leitura 
    
    if(file == NULL)
    {
    	printf(" O usu�rio n�o se encontra no sistema!\n");
    	system("pause");
	}

		
}


int main ()
	{
	int opcao=0; //Definindo Variaveis 
	int laco=1;
	
	for (laco=1;laco=1;) // La�o de repeti��o
	{
		
		system("cls"); // Respons�vel por limpar a tela 
		
		setlocale(LC_ALL,"Portuguese"); // Definindo a linguagem 
	
		printf("### Cart�rio da EBAC ###\n\n"); // Inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); // Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio 
	
		system("cls"); // Responsavel por limpar a tela
	
	
		switch(opcao) // inicio da sele��o do menu
		{
			case 1:
			registro (); // chamada de func��es 
			break;
		
			case 2:	
			consulta ();
			break;
		
			case 3:
			deletar ();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!");
			return 0;
			break;
		
			default:
			printf("Essa op��o n�o est� dispon�vel\n");
			system("pause");	
		
		} // fim da sele��o
	
	}	
}
