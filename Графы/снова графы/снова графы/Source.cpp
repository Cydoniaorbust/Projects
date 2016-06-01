#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
using namespace std;
const int max = 7;
struct rec1 
{
	int node;
	rec1 *next;
};
struct rec2
{
	int node;
	rec2 *next;
	rec2 *parent;
};
rec1 *sp[max];
int first, last, k = 0;
rec2 *top, *iter;
int labels[max];
void randgraf() 
{
	int i, j, x, first;
	rec1 *ptr;
	for (i = 0;i < max;i++)
	{
		first = 1;
		for (j = 0;j < max;j++)
		{
			x = rand() % 10 + 1;
			if (x>5&&i!=j)
				if (first) 
				{
					first = 0;
					sp[i] = new rec1;
					ptr = sp[i];
					ptr->next = NULL;
					ptr->node = j;
				}
				else 
				{
					ptr = new rec1;
					ptr->next = NULL;
					ptr->node = j;
				}
		}
	}
}
void outgraf()
{
	rec1 *ptr;
	int i;
	for (i = 0;i < max;i++)
	{
		ptr = sp[i];
		cout << i << ' ';
		while (ptr != NULL)
		{
			cout << ptr->node << ' ';
			ptr = ptr->next;
		}
		cout << '\n';
	}
}
int in(int j, int *X, int n)
{
	for (int i = 0;i < n;i++)
		if (j == X[i]) return 1;
	return 0;
}
void successful(rec2* bufer)
{
	cout << "ѕуть";
	while (bufer != NULL)
	{
		cout << bufer->node << " ";
		bufer = bufer->parent;
	}
}
void Addusel(rec2 *buf)
{
	rec1 *bufer;
	bufer = sp[buf->node];
	while ((bufer != NULL) && (iter->node != last))
		if (!in(bufer->node, labels, max)) 
		{
			iter->next = new rec2;
			iter = iter->next;
			iter->next = NULL;
			iter->node = bufer->node;
			labels[k++] = iter->node;
			iter->parent = buf;
		}
		else bufer = bufer->next;
}
rec2* search(rec2 *bufiter)
{
	if (iter->node == last) return iter;
	else if (bufiter != NULL)
	{
		Addusel(bufiter);
		search(bufiter->next);
	}
	else return NULL;
}
void main()
{
	rec2 *resultat;
	setlocale(LC_ALL, "");
	srand((unsigned)time(NULL));
	for (int i = 0;i < max;i++)
		labels[i] = -1;
	for (int i = 0;i < max;i++)
		sp[i] = NULL;
	randgraf();
	outgraf();
	cout << "¬ведите первый и последний узлы";
	cin >> first >> last;
	top = new rec2;
	top->parent = NULL;
	top->next = NULL;
	top->node = first;
	labels[k++] = top->node;
	iter = top;
	resultat = search(iter);
	if (iter != NULL)
		successful(iter);
	else cout << "ѕуть не найден";
	system("pause");
}