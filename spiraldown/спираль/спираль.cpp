// спираль.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

const int n = 3;
int i, j, k;

void printm(int **a){
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << a[i][j] << "\t";
		cout << endl;
	}
}

void spiral(int **&a){
	int s = n,k;
	for (i = 0; i < s; i++)
	{
		k = 4 *s - 1;
		for (j = i; j < s; j++)
			{			
				a[j][i] = k*i + j + 1;			
				a[n-1-i][j] = (k-1)*i+s + j;
				a[n - j - 1][n - i - 1] = (k-2)*i+2*(s-1)+1+j;
				a[i][n - j - 1] = (k - 3)*i + 3 * (s - 1) + j + 1;
			}	
		a[i][i] = k*i + i+1;			
		s--;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	system("MODE CON: COLS=140 LINES=70");
	int **a = new int*[n];
	for (i = 0; i < n; i++)
		a[i] = new int[n];
	spiral(a);
	printm(a);
	system("pause");
	return 0;

}

