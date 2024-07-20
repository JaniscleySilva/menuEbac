
#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca repons�vel por cuidar das strings

int registro() //fun��o respons�vel por cadastrar usu�rios no sistema
{
	//in�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando inform��o do usu�rio
	scanf("%s", cpf); //%s refere-se ao armazenamento de string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); //salva o valor da vari�vel
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
	
	if(file == NULL) //se o cpf digitado n�o existir no registro, � exibido mensagem de erro.
	{
		printf("\nN�o foi poss�vel abrir o arquivo. Arquivo n�o localizado!\n\n");
	}
	
	while(fgets(conteudo, 100, file) != NULL)
	{
		printf("\nInforma��es do usu�rio: \n");
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
	scanf("%s", cpf); //coleta informa��o do usu�rio

	remove(cpf);

	FILE *file;
	file = fopen(cpf, "r");

	if(file == NULL) //verifica se o cpf digitado existe no banco de dados. Se n�o existir exibe mensagem de erro.
	{
		printf("\nUsu�rio n�o localizado!\n\n");
		system("pause");
	}
	
	fclose(file);
}

int main()
{
	int opcao=0; //definindo vari�veis
	int x=1;
	
	for(x=1;x=1;) //definindo o looping do sistema
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); 
		//setlocale indica para a m�quina a liguagem que quero atribuir e no caso do portugu�s, a m�quina passar� a entender quando atribuir acentos ou outros caracteres especiais da l�ngua.

		printf("### Cart�rio da EBAC ###\n\n");	
		//A adi��o das hashtags atribui apenas espa�amento ao c�digo, como forma de perfumaria e por estar dentro das aspas, ela n�o representa nenhum comando.
		//J� o comando \n\n (duplo) indica que deve pula uma linha.

		printf("Escolha a op��o desejada do menu:\n\n"); //in�cio do menu
		printf("\t1 - Registrar nomes\n"); //"\t" indica espa�amento antes do texto, como um TAB)
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
		
		system("cls"); //respons�vel por limpar a tela
	
		switch(opcao) //in�cio da sele��o do menu
		{
			case 1:
			registro(); //chamada das fun��es
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
			printf("Esta op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
		} //fim da sele��o
	}
}	
