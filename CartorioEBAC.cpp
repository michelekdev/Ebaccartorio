#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca das string

int registro() //função responsavel por cadastrar usuários no sistema
{
	//inicio da criação de variáveis/string
	char arquivo[40]; //string - conjunto de variaiveis 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
		
	printf("Você escolheu o resgistro de nomes !\n");
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",cpf); //armazena a informação do usuário, %s refere-se a string 
	
	strcpy(arquivo,cpf); //copia os valores das string, atribuiu o valor do cpf para arquivo
	
	FILE *file; //cria o arquivo de armazenamento
	file = fopen(arquivo,"w"); // cria o arquivo e o "w" significa escrever 
	fprintf(file,cpf); //salva o valor da variavel CPF no arquivo 
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); // "a" atualiza o arquivo 
	fprintf(file, ","); //adiciona uma vírgula no arquivo 
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome); //armazena a informação do usuário
	
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

int consulta() // função responsável por consultar os dados do usuário 
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem 
	
	char cpf[40];
	char conteudo[100];
	
	printf("Você escolheu consultar os nomes !\n");
	printf ("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // "r" lê o arquivo escolhido
	
	if(file == NULL) 
	{
		printf("Arquivo inexistente, não foi possível abrir o arquivo \n");
	}
	
	while(fgets(conteudo, 100, file) != NULL)
	{
		printf("\n Essas são as informações do usuário: ");
		printf("%s", conteudo); 
		printf("\n\n") ;
	}

	system("pause");
}

int deletar() //função responsável por delelar os usuários 
{
	
	char cpf[40];

	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf); //deletar 
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usuário não se encontra no sistema ! \n");
		system("pause");
	}
	
}

int main ()
{
	int opcao=0; //Definindo variável, toda variavél precisa ter um valor atribuido
	int laco=1;
	
	for(laco=1;laco=1;) //laço de repetição
	{
		system("cls"); // limpa a tela 
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem 
	
		printf("\t#Cartório da EBAC#\n\n\n"); //início do menu
		printf("Escolha aopção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("\t4 - Sair do programa\n\n");
		printf("Opção:"); //fim do menu
	
		scanf("%d", &opcao); // armazenando a escolha do usário
	
		system("cls"); // limpa a tela 
		
		switch(opcao) //encadeamento, inicio da seleção do menu
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
			printf("Essa opção não está disponível\n");
			system("pause");
			break;
		}// fim da seleção
	}
}

