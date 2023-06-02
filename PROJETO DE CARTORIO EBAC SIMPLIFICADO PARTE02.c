#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o responsavel pelo cadastro no sistema
{
	//Inicio da cria��o de vari�veis/string
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string
		
	printf("Digite o CPF a ser cadastrado: \n"); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s referente a valores de string. Salvar
		
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string, Salvar
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //Reconhece o arquivo e abre o arquivo. "w" significa criar uma nova e escrever
	fprintf(file,cpf); //Armazenou o arquivo na pasta.
	fclose(file); //fechamento do arquivo
	
	file = fopen(arquivo, "a"); //Reconhece o arquivo e abre. Letra "a" significa atualizar as informa��es dentro do pasta
	fprintf(file,","); //Armazena dentro da pasta selecionada
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: \n"); //Coletando as informa��es do usu�rio
	scanf("%s",nome); //%s referante a valores de string. salvar
	
	file = fopen(arquivo, "a"); //Reconhece o arquivo e abre a pasta. Letra "a" significa atualizar informa��es dentro da pasta
	fprintf(file,nome); //Armazena dentro da pasta selecionada
	fclose(file); //Fecha arquivo
	
	file = fopen(arquivo, "a"); // Letra A atualiza as informa��es dentro do pasta
	fprintf(file,","); //Armazena dentro da pastga selecionada
	fclose(file); //Fecha pasta ou arquivo
	
	printf("Digite o sobrenome a ser cadastrado: \n"); //Coletando informa��es do usu�rio
	scanf("%s",sobrenome); //%s referente a valores da String. Salvar
	
	file = fopen(arquivo, "a"); //Reconhece arquivo e abre a pasta. Letra "a" significa atualizar informa��es dentro da pasta selecionada.
	fprintf(file,sobrenome); //Armazena conteudo dentro da pasta selecionada
	fclose(file); //Fecha arquivo/pasta
	
	file = fopen(arquivo, "a"); //Reconhece arquivo e abre a pasta/arquivo. Letra "a" atualiza as informa��es dentro do pasta
	fprintf(file,",");  //Armazena conteudo dentro da pasta/conteudo.
	fclose(file); //Fecha pasta/arquivo
	
	printf("Digite o cargo a ser cadastrado: \n"); //Coletendo informa��es do usu�rio
	scanf("%s",cargo); //%s referente a valores da string
	
	file = fopen(arquivo, "a"); //|Reconhece arquivo e abre a pasta. Letra "a" atualiza as informa�oes na pasta/arquivo.
	fprintf(file,cargo); //Armazena conteudo dentro da pasta
	fclose(file); //fecha pasta/arquivo
	
	system("pause"); //pausa no sistema tempo para o usu�rio ler a informa��o
	
}

int consultar() // Responsavel por executar consulta
{
	setlocale(LC_ALL, "Portuguese"); //Localiza��o ortogr�fica
	
	char cpf[40]; //vari�vel. [40]significa a quantindade de caracteres dentro da variavel.
	char conteudo[200]; //variavel [200] significa a quantidade de caracteres dentro da variavel. 
	
	printf("Digite o CPF a ser consultado: \n"); //Coletando informa��es do usu�rio
	scanf("%s", cpf); //Referente a valore da string
	
	FILE *file; //Informa a programa que estamos criando um arquivo e para buscar dentro desse arquivo.
	file = fopen(cpf, "r"); //informa para buscar dentro do arquivo/pasta. Letra "r" siginifica leitura.
	
	if(file == NULL) // Estamos afirmando se a busca for algo inexistente, n�o estiver salvo.
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado! \n"); //Passar informa��o ao usu�rio.
	}
	
	while(fgets(conteudo, 200, file) != NULL) //la�o de repeti��o
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n"); //Coletando informa��o do usu�rio.
		printf("%s", conteudo); //referente a valores da string
		printf("\n\n"); //pular linha
		
		system("pause"); //Pausa para o usu�rio ler informa��o.
	}
	
}

int deletar() //reponsavel por executar fun��o
{
	char cpf[40]; //Variavel. [40] quantidade de caracteres dentro da variavel.
	
	printf("Digite o CPF do usu�rio a ser deletado: \n"); //Coletando informa��es do usu�rio
	scanf("%s",cpf); //referente a valres da string. Salvar
	
	remove(cpf); //fun��o de remover
	
	FILE *file; //informando o programa que estamos criando a fun��o de arquivo e para buscar dentro do arquivo/pasta
	file = fopen(cpf,"r"); //Buscar dentro do arquivo/pasta e abrir. A letra "r" significa leitura.
	
	if(file == NULL) //Estamos afirmando se a busca for algo inexistente, n�o estiver salvo. passar a informa��es ao usu�rio
	{
		printf("O usu�rio n�o se encontra no sistema!\n"); //Informa��es para o usu�rio
		system("pause"); //Pause do sistema
	}
	

}

int main()
{
	int opcao=0; //Defini��o das vari�veis
	int laco=1;
	
	for(laco=1;laco=1;) //indicando para voltar ao menu
	{
	
		system("cls"); //limpar tela a seguir
			
		setlocale(LC_ALL, "Portuguese"); //Localiza��o ortogr�fica
	
		printf("\t\t### CART�RIO DA EBAC ###\n\n"); //Inico do menu
		printf("\tEscolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes dos aulos\n");
		printf("\t2 - Consultar nomes dos aulos\n");
		printf("\t3 - Deletar nomes dos aulos\n\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); //Fim do menu
	
		scanf("%d" , &opcao); //Armazenamento a escolh do usu�rio
	
		system ("cls"); //limpar tela a seguir
		
		switch(opcao) //Inico da sele��o do menu
		{
			case 1:
			registro(); //Chamar fun��es
			break; //Pause do sistema
			
			case 2:
			consultar(); //Chamar fun��es
			break; //Pause do sistema
			
			case 3:
			deletar(); //Chamar fun��es
			break; //Pause do sistema
			
			case 4: 
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break; 
			
			default:
			printf("Essa opcao n�o � valida\n"); //Informa��es para o usu�rio
			system("pause"); //Pause do sistema
			break;	//Pause do sistema				
		} //Final da sele��o
		
		
	}
	




}
