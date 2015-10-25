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
} *lista_alunos;

void iniciar_lista();
int esta_vazio();
void inserir_aluno();
void listar_alunos();
alunos *primeiro_elemento();
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
			alunos *p = primeiro_elemento();
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
	delete lista_alunos;
}

void iniciar_lista()
{
	lista_alunos = NULL;
}

int esta_vazio()
{
	system("cls");
	int total;
	if (lista_alunos == NULL)
		total = 0;
	else
	{
		alunos *p;
		p = lista_alunos;
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
	system("cls");
	if (lista_alunos == NULL)
	{
		cout << "Nenhum aluno cadastrado." << endl;
		cout << "Pressione uma tecla para continuar..." << endl;
		getch();		
		return;
	}
	
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

alunos *primeiro_elemento()
{
	return lista_alunos;
}

void remover_aluno()
{
	alunos *p;
	p = lista_alunos;
	lista_alunos = lista_alunos->proximo;
	delete p;
	
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
	cout << "5 - PRIMEIRO ELEMENTO" << endl;
	cout << "0 - SAIR" << endl;
	cout << "Digite uma opção: ";
}

void limpar_teclado()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
