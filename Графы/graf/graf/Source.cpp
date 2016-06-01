#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
using namespace std;
struct Row {
	int Num;
	Row *Next;
	Row *Colum;
};
void GetMas(int **A, int N)
{
	int i, j, x;
	srand((unsigned int)time(NULL));
	for (i = 0;i < N;i++)
	{
		for (j = 0;j < N;j++)
		{
			x = rand()%100;
			if (x > 50)
				A[i][j] = 1;
			else
				A[i][j] = 0;
		}
	}
	for (i = 0;i < N;i++)
		A[i][i] = 0;
}
void OutMas(int **A, int N)
{
	int i, j;
	cout << '|' << ' ';
	for (i = 0;i < N;i++)
	{
		cout << i << ' ';
	}
	cout << '\n';
	for (i = 0;i < N;i++)
	{
		cout << i << ' ';
		for (j = 0;j < N;j++)
		{
			cout << A[i][j] << ' ';
		}
		cout << '\n';
	}
}
Row *Convert(int **A, int N, Row *Top)
{
	int i, j;
	Row *P, *T, *C;
	P = new Row;
	P->Num = 0;
	P->Next = NULL;
	P->Colum = NULL;
	Top = P;
	for (i = 1;i < N;i++)
	{
		T = new Row;
		T->Num = i;
		T->Next = NULL;
		T->Colum = NULL;
		P->Next = T;
		P = T;
	}
	cout << '\n' << "Распечатаем очередь вершин" << '\n';
	P = Top;
	while (P != NULL)
	{
		cout << '\n' << P->Num;
		P = P->Next;
	}
	T = Top;
	P = Top;
	for (i = 0;i < N;i++)
	{
		for (j = 0;j < N;j++)
		{
			if (A[i][j] == 1)
			{
				C = new Row;
				C->Num = j;
				C->Next = NULL;
				C->Colum = NULL;
				P->Colum = C;
				P = C;
			}
		}
		T = T->Next;
		P = T;
	}
	return Top;
}
void OutSpis(Row *Top)
{
	Row *P, *T;
	P = Top;
	T = P->Colum;
	while (P != NULL)
	{
		cout << P->Num << ' ';
		while (T != NULL)
		{
			cout << T->Num << ' ';
			T = T->Colum;
		}
		P = P->Next;
		if(P)
			T = P->Colum;
		cout << '\n';
	}
}
void main()
{
	setlocale(LC_ALL, "");
	Row *Top=NULL;
	int **A;
	system("cls");
	int N;
	cout << "\nВведите количество вершин графа";
	cin >> N;
	A = new int*[N];
	for (int i = 0;i < N;i++)
	{
		A[i] = new int[N];
	}
	GetMas(A, N);
	OutMas(A, N);
	Top = Convert(A, N, Top);
	cout << '\n' << Top->Num << '\n';
	cout << "Список инцидентности\n";
	OutSpis(Top);
	system("pause");
}