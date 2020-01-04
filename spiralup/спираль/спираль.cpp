// спираль.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
using namespace std;

const int n = 10;
int i, j;

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
			//if (j != s - 1)
			{			
				a[i][j] = k*i + j + 1;			
				a[j][n - i - 1] = (k-1)*i+s + j;
				a[n - 1 - i][n - j - 1] = (k-2)*i+2*(s-1)+1+j;
				a[n - j - 1][i] = (k - 3)*i+3 * (s - 1) + j + 1;
			}	
		a[i][i] = k*i + i+1; //костыль который убирает условие if			
		s--;
	}
}

/*void spiral2(int **&a){
	int s = n, k;
	for (i = 0; i < s; i++)
	{
		k = 4 * s - 1;
		for (j = i; j < s; j++)
			if (j != s - 1)
		{
			a[i][j] = k*i + j + 1;
			a[j][n - i - 1] = (k - 1)*i + s + j;
			a[n - 1 - i][n - j - 1] = (k - 2)*i + 2 * (s - 1) + 1 + j;
			a[n - j - 1][i] = (k - 3)*i + 3 * (s - 1) + j + 1;
		}
		a[i][i] = k*i + i + 1; //костыль который убирает условие if			
		s--;
	}
}*/
int _tmain(int argc, _TCHAR* argv[])
{
	system("MODE CON: COLS=140 LINES=70");
	int **a = new int*[n];
	for (i = 0; i < n; i++)
		a[i] = new int[n];
	//unsigned int start= clock();
	spiral(a);
	//unsigned int end = clock();
	//cout << end - start<<endl;
	//start = clock();
	//spiral2(a);
	//end = clock();
	//cout << end - start << endl;
	printm(a);
	system("pause");
	return 0;

}

