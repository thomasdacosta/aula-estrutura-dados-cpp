#include <iostream>
#include <strings.h>
#include <conio.h>
#include <limits>

using namespace std;

struct alunos
{
	char nome[100];
	int idade;
	alunos *proximo;
} *lista_alunos;

void iniciar_lista();
void inserir_aluno();
void listar_alunos();
void menu();
void limpar_teclado();

int main()
{
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
	}
	delete lista_alunos;
}

void iniciar_lista()
{
	lista_alunos = NULL;
}

void inserir_aluno()
{
	limpar_teclado();
	alunos *novo_aluno = new alunos;
	
	cout << "Digite o nome do aluno:" << endl;
	gets(novo_aluno->nome);
	
	cout << "Digite a idade do aluno:" << endl;
	cin >> novo_aluno->idade;
	
	novo_aluno->proximo = NULL;
	
	if (lista_alunos == NULL)
		lista_alunos = novo_aluno;
	else 
	{
		alunos *p;
		p = lista_alunos;
		
		while (p->proximo != NULL)
			p = p->proximo;
		
		p->proximo = novo_aluno;
	}
}

void listar_alunos()
{
	alunos *p;
	p = lista_alunos;
	
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

void menu()
{
	system("cls");
	cout << "1 - INSERIR" << endl;
	cout << "2 - LISTAR" << endl;
	cout << "0 - SAIR" << endl;
}

void limpar_teclado()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
