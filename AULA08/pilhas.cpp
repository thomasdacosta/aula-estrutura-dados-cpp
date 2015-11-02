#include <iostream>
#include <strings.h>
#include <conio.h>
#include <limits>
#include <locale.h>

using namespace std;

struct alunos
{
	char nome[100];
	int idade;
	alunos *proximo;
} *primeiro, *ultimo;

void iniciar_lista();
int esta_vazio();
void inserir_aluno();
void listar_alunos();
alunos *ultimo_elemento();
void remover_aluno();
void menu();
void limpar_teclado();

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int opcao = -1;
	iniciar_lista();
	while (opcao != 0)
	{
		menu();
		cin >> opcao;
		
		if (opcao == 1)
			inserir_aluno();
		else if (opcao == 2)
			listar_alunos();
		else if (opcao == 3)
			remover_aluno();
		else if (opcao == 4)
		{
			cout << "Tamanho:" << esta_vazio();
			getch();
		}
		else if (opcao == 5)
		{
			alunos *p = ultimo_elemento();
			if (p == NULL)
			{
				cout << "Nenhum aluno cadastrado." << endl;
				cout << "Pressione uma tecla para continuar..." << endl;
				getch();		
			}
			else
			{
				system("cls");
				cout << "------------------------------------" << endl;
				cout << "Nome do Aluno:" << p->nome << endl;
				cout << "Idade do Aluno:" << p->idade << endl;
				cout << "------------------------------------" << endl;
				getch();
			}
		}
	}
	delete primeiro;
}

void iniciar_lista()
{
	primeiro = NULL;
}

int esta_vazio()
{
	system("cls");
	int total;
	if (primeiro == NULL)
		total = 0;
	else
	{
		alunos *p;
		p = primeiro;
		total = 1;
		
		while (p->proximo != NULL)
		{
			p = p->proximo;
			total++;
		}
	}
	
	return total;
}

void inserir_aluno()
{
	system("cls");
	limpar_teclado();
	alunos *novo_aluno = new alunos;
	
	cout << "Digite o nome do aluno:" << endl;
	fgets(novo_aluno->nome, sizeof(novo_aluno->nome), stdin);
	
	cout << "Digite a idade do aluno:" << endl;
	cin >> novo_aluno->idade;
	
	novo_aluno->proximo = NULL;
	
	if (primeiro == NULL)
	{
		primeiro = novo_aluno;
		ultimo = novo_aluno;
	}
	else 
	{
		alunos *p;
		p = primeiro;
		
		while (p->proximo != NULL)
			p = p->proximo;
		
		p->proximo = novo_aluno;
		ultimo = novo_aluno;
	}
}

void listar_alunos()
{
	system("cls");
	if (primeiro == NULL)
	{
		cout << "Nenhum aluno cadastrado." << endl;
		cout << "Pressione uma tecla para continuar..." << endl;
		getch();		
		return;
	}
	
	alunos *p;
	p = primeiro;
	
	if (p->proximo == NULL) 
	{
		cout << "------------------------------------" << endl;
		cout << "Nome do Aluno:" << p->nome << endl;
		cout << "Idade do Aluno:" << p->idade << endl;
		cout << "------------------------------------" << endl;
	}
	else
	{
		while (p != NULL)
		{
			cout << "------------------------------------" << endl;
			cout << "Nome do Aluno:" << p->nome << endl;
			cout << "Idade do Aluno:" << p->idade << endl;
			cout << "------------------------------------" << endl;
			p = p->proximo;
		}
	}
	getch();
}

alunos *ultimo_elemento()
{
	return ultimo;
}

void remover_aluno()
{
	alunos *p = primeiro;
	while (p->proximo != ultimo)
		p = p->proximo;
	
	delete p->proximo;
		
	ultimo = p;
	p->proximo = NULL;

	cout << "Aluno excluído com sucesso !!!" << endl;
	getch();
}

void menu()
{
	system("cls");
	cout << "1 - INSERIR ALUNOS" << endl;
	cout << "2 - LISTAR ALUNOS" << endl;
	cout << "3 - EXCLUIR ALUNOS" << endl;
	cout << "4 - TAMANHO DA LISTA" << endl;
	cout << "5 - ULTIMO ELEMENTO" << endl;
	cout << "0 - SAIR" << endl;
	cout << "Digite uma opção: ";
}

void limpar_teclado()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
