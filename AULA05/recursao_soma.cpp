#include <iostream>

using namespace std;

int soma(int v[], int n);

int main()
{
	int soma_vetor[5] = { 8, 0, 1, 3, 5};
	cout << soma(soma_vetor, 5);
}

int soma(int v[], int n)
{
	if (n == 0)
		return 0;
	else
	{
		int s = soma(v, n-1);
		if (v[n-1] > 0)
			s += v[n-1];
		return s;			
	}
}
