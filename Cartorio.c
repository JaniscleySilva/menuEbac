
#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca reponsável por cuidar das strings

int registro() //função responsável por cadastrar usuários no sistema
{
	//início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informção do usuário
	scanf("%s", cpf); //%s refere-se ao armazenamento de string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" acrescentar dados no arquivo (append)
	fprintf(file, ","); //atualizando para separar o resultado de registros por ","
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	system("pause");	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //abre o arquivo e realiza leitura "r"
	
	if(file == NULL) //se o cpf digitado não existir no registro, é exibido mensagem de erro.
	{
		printf("\nNão foi possível abrir o arquivo. Arquivo não localizado!\n\n");
	}
	
	while(fgets(conteudo, 100, file) != NULL)
	{
		printf("\nInformações do usuário: \n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");	
}

int deletar()
{
	char cpf[40];

	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf); //coleta informação do usuário

	remove(cpf);

	FILE *file;
	file = fopen(cpf, "r");

	if(file == NULL) //verifica se o cpf digitado existe no banco de dados. Se não existir exibe mensagem de erro.
	{
		printf("\nUsuário não localizado!\n\n");
		system("pause");
	}
	
	fclose(file);
}

int main()
{
	int opcao=0; //definindo variáveis
	int x=1;
	
	for(x=1;x=1;) //definindo o looping do sistema
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); 
		//setlocale indica para a máquina a liguagem que quero atribuir e no caso do português, a máquina passará a entender quando atribuir acentos ou outros caracteres especiais da língua.

		printf("### Cartório da EBAC ###\n\n");	
		//A adição das hashtags atribui apenas espaçamento ao código, como forma de perfumaria e por estar dentro das aspas, ela não representa nenhum comando.
		//Já o comando \n\n (duplo) indica que deve pula uma linha.

		printf("Escolha a opção desejada do menu:\n\n"); //início do menu
		printf("\t1 - Registrar nomes\n"); //"\t" indica espaçamento antes do texto, como um TAB)
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
		
		system("cls"); //responsável por limpar a tela
	
		switch(opcao) //início da seleção do menu
		{
			case 1:
			registro(); //chamada das funções
			break;
			
			case 2:	
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Esta opção não está disponível!\n");
			system("pause");
			break;
		} //fim da seleção
	}
}	
