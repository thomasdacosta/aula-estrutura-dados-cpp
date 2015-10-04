#include <iostream>
#include <locale.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int vetor_numeros[10] = {0,1,2,3,4,5,6,7,8,9};
	int posicao = 5;
	
	cout << "Atual:" << vetor_numeros[posicao] << endl;
	cout << "Anterior:" << vetor_numeros[posicao-1] << endl;
	cout << "Próximo:" << vetor_numeros[posicao+1] << endl;
}
