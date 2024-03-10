#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca das string

int registro() //fun��o responsavel por cadastrar usu�rios no sistema
{
	//inicio da cria��o de vari�veis/string
	char arquivo[40]; //string - conjunto de variaiveis 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
		
	printf("Voc� escolheu o resgistro de nomes !\n");
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf); //armazena a informa��o do usu�rio, %s refere-se a string 
	
	strcpy(arquivo,cpf); //copia os valores das string, atribuiu o valor do cpf para arquivo
	
	FILE *file; //cria o arquivo de armazenamento
	file = fopen(arquivo,"w"); // cria o arquivo e o "w" significa escrever 
	fprintf(file,cpf); //salva o valor da variavel CPF no arquivo 
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); // "a" atualiza o arquivo 
	fprintf(file, ","); //adiciona uma v�rgula no arquivo 
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome); //armazena a informa��o do usu�rio
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system ("pause");
}

int consulta() // fun��o respons�vel por consultar os dados do usu�rio 
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem 
	
	char cpf[40];
	char conteudo[100];
	
	printf("Voc� escolheu consultar os nomes !\n");
	printf ("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // "r" l� o arquivo escolhido
	
	if(file == NULL) 
	{
		printf("Arquivo inexistente, n�o foi poss�vel abrir o arquivo \n");
	}
	
	while(fgets(conteudo, 100, file) != NULL)
	{
		printf("\n Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo); 
		printf("\n\n") ;
	}

	system("pause");
}

int deletar() //fun��o respons�vel por delelar os usu�rios 
{
	
	char cpf[40];

	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf); //deletar 
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usu�rio n�o se encontra no sistema ! \n");
		system("pause");
	}
	
}

int main ()
{
	int opcao=0; //Definindo vari�vel, toda variav�l precisa ter um valor atribuido
	int laco=1;
	
	for(laco=1;laco=1;) //la�o de repeti��o
	{
		system("cls"); // limpa a tela 
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem 
	
		printf("\t#Cart�rio da EBAC#\n\n\n"); //in�cio do menu
		printf("Escolha aop��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("\t4 - Sair do programa\n\n");
		printf("Op��o:"); //fim do menu
	
		scanf("%d", &opcao); // armazenando a escolha do us�rio
	
		system("cls"); // limpa a tela 
		
		switch(opcao) //encadeamento, inicio da sele��o do menu
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por usar o sistema");
			return 0; 
			
			default:
			printf("Essa op��o n�o est� dispon�vel\n");
			system("pause");
			break;
		}// fim da sele��o
	}
}

