#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <stdio.h> //biblioteca de comunicação com o usuário
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsavel pelo cadastro no sistema
{
	//Inicio da criação de variáveis/string
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
		
	printf("Digite o CPF a ser cadastrado: \n"); //Coletando informação do usuário
	scanf("%s", cpf); //%s referente a valores de string. Salvar
		
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string, Salvar
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //Reconhece o arquivo e abre o arquivo. "w" significa criar uma nova e escrever
	fprintf(file,cpf); //Armazenou o arquivo na pasta.
	fclose(file); //fechamento do arquivo
	
	file = fopen(arquivo, "a"); //Reconhece o arquivo e abre. Letra "a" significa atualizar as informações dentro do pasta
	fprintf(file,","); //Armazena dentro da pasta selecionada
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: \n"); //Coletando as informações do usuário
	scanf("%s",nome); //%s referante a valores de string. salvar
	
	file = fopen(arquivo, "a"); //Reconhece o arquivo e abre a pasta. Letra "a" significa atualizar informações dentro da pasta
	fprintf(file,nome); //Armazena dentro da pasta selecionada
	fclose(file); //Fecha arquivo
	
	file = fopen(arquivo, "a"); // Letra A atualiza as informações dentro do pasta
	fprintf(file,","); //Armazena dentro da pastga selecionada
	fclose(file); //Fecha pasta ou arquivo
	
	printf("Digite o sobrenome a ser cadastrado: \n"); //Coletando informações do usuário
	scanf("%s",sobrenome); //%s referente a valores da String. Salvar
	
	file = fopen(arquivo, "a"); //Reconhece arquivo e abre a pasta. Letra "a" significa atualizar informações dentro da pasta selecionada.
	fprintf(file,sobrenome); //Armazena conteudo dentro da pasta selecionada
	fclose(file); //Fecha arquivo/pasta
	
	file = fopen(arquivo, "a"); //Reconhece arquivo e abre a pasta/arquivo. Letra "a" atualiza as informações dentro do pasta
	fprintf(file,",");  //Armazena conteudo dentro da pasta/conteudo.
	fclose(file); //Fecha pasta/arquivo
	
	printf("Digite o cargo a ser cadastrado: \n"); //Coletendo informações do usuário
	scanf("%s",cargo); //%s referente a valores da string
	
	file = fopen(arquivo, "a"); //|Reconhece arquivo e abre a pasta. Letra "a" atualiza as informaçoes na pasta/arquivo.
	fprintf(file,cargo); //Armazena conteudo dentro da pasta
	fclose(file); //fecha pasta/arquivo
	
	system("pause"); //pausa no sistema tempo para o usuário ler a informação
	
}

int consultar() // Responsavel por executar consulta
{
	setlocale(LC_ALL, "Portuguese"); //Localização ortográfica
	
	char cpf[40]; //variável. [40]significa a quantindade de caracteres dentro da variavel.
	char conteudo[200]; //variavel [200] significa a quantidade de caracteres dentro da variavel. 
	
	printf("Digite o CPF a ser consultado: \n"); //Coletando informações do usuário
	scanf("%s", cpf); //Referente a valore da string
	
	FILE *file; //Informa a programa que estamos criando um arquivo e para buscar dentro desse arquivo.
	file = fopen(cpf, "r"); //informa para buscar dentro do arquivo/pasta. Letra "r" siginifica leitura.
	
	if(file == NULL) // Estamos afirmando se a busca for algo inexistente, não estiver salvo.
	{
		printf("Não foi possivel abrir o arquivo, não localizado! \n"); //Passar informação ao usuário.
	}
	
	while(fgets(conteudo, 200, file) != NULL) //laço de repetição
	{
		printf("\nEssas são as informações do usuário: \n"); //Coletando informação do usuário.
		printf("%s", conteudo); //referente a valores da string
		printf("\n\n"); //pular linha
		
		system("pause"); //Pausa para o usuário ler informação.
	}
	
}

int deletar() //reponsavel por executar função
{
	char cpf[40]; //Variavel. [40] quantidade de caracteres dentro da variavel.
	
	printf("Digite o CPF do usuário a ser deletado: \n"); //Coletando informações do usuário
	scanf("%s",cpf); //referente a valres da string. Salvar
	
	remove(cpf); //função de remover
	
	FILE *file; //informando o programa que estamos criando a função de arquivo e para buscar dentro do arquivo/pasta
	file = fopen(cpf,"r"); //Buscar dentro do arquivo/pasta e abrir. A letra "r" significa leitura.
	
	if(file == NULL) //Estamos afirmando se a busca for algo inexistente, não estiver salvo. passar a informações ao usuário
	{
		printf("O usuário não se encontra no sistema!\n"); //Informações para o usuário
		system("pause"); //Pause do sistema
	}
	

}

int main()
{
	int opcao=0; //Definição das variáveis
	int laco=1;
	
	for(laco=1;laco=1;) //indicando para voltar ao menu
	{
	
		system("cls"); //limpar tela a seguir
			
		setlocale(LC_ALL, "Portuguese"); //Localização ortográfica
	
		printf("\t\t### CARTÓRIO DA EBAC ###\n\n"); //Inico do menu
		printf("\tEscolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes dos aulos\n");
		printf("\t2 - Consultar nomes dos aulos\n");
		printf("\t3 - Deletar nomes dos aulos\n\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //Fim do menu
	
		scanf("%d" , &opcao); //Armazenamento a escolh do usuário
	
		system ("cls"); //limpar tela a seguir
		
		switch(opcao) //Inico da seleção do menu
		{
			case 1:
			registro(); //Chamar funções
			break; //Pause do sistema
			
			case 2:
			consultar(); //Chamar funções
			break; //Pause do sistema
			
			case 3:
			deletar(); //Chamar funções
			break; //Pause do sistema
			
			case 4: 
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break; 
			
			default:
			printf("Essa opcao não é valida\n"); //Informações para o usuário
			system("pause"); //Pause do sistema
			break;	//Pause do sistema				
		} //Final da seleção
		
		
	}
	




}
