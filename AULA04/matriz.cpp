#include <iostream>

using namespace std;

int main()
{
	int valor[4][4] = { 
						{0, 0 ,0 ,0},
						{0, 1 ,1 ,0},
						{0, 1 ,1 ,0},
						{0, 0 ,0 ,0} 
					  };
					  
	valor[0][2] = 22;
					  
	for (int i=0;i<=3;i++)
	{
		for (int j=0;j<=3;j++)
		{
			cout << valor[i][j];
		}
		cout << endl;
	}
	
}
