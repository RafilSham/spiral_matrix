// спираль.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
using namespace std;

const int n = 7;
int i, j;
void nullmass(int **a){
	for (i = 0; i < n; i++)
	for (j = 0; j < n; j++)
		a[i][j] = 0;
}
void printm(int **a){
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << a[i][j] << "\t";
		cout << endl;
	}
}

void spiral(int **&a){
	int s=n,k=s;
	for (i = 0; i<s; i++)
	{
		for (j = i; j <s; j++)
			{			
				a[i][j] = k*k-j+i;			
				a[j][n - i - 1] = k*(k-1)-j+i+1;
				a[n - 1 - i][n - j - 1] = k*k-2*k-j+i+2;
				a[n - j - 1][i] = k*k-3*k-j+i+3;
			}	
		a[i][i] = k*k;
		s--;
		k = k - 2;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	system("MODE CON: COLS=140 LINES=70");
	int **a = new int*[n];
	for (i = 0; i < n; i++)
		a[i] = new int[n];
	nullmass(a);
	spiral(a);
	printm(a);
	system("pause");
	return 0;

}

