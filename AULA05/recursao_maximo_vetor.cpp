#include <iostream>

using namespace std;

int maximo_vetor(int v[], int n);

int main()
{
	int vetor[10] = { 2, 1, 10, 6, 1, 9, 1, 1, 0, 3 };
	cout << maximo_vetor(vetor, 10);
}

int maximo_vetor(int v[], int n)
{
	if (n == 1)
		return v[0];
	else
	{
		int x;
		x = maximo_vetor(v, n-1);
		if (x > v[n-1])
			return x;
		else
			return v[n-1];
	}
}
