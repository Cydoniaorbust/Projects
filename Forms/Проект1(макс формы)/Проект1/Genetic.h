#pragma once
#include <math.h>
#include <stdlib.h>
ref class Genetic
{
public:
	Genetic();
	double a = 1.2, b = 2.2, c = 3.3;
	double mod()
	{
		return sqrt(a*a + b*b + c*c);
	}
	double prigodnost(int **mass,int n, int m, int i)
	{
		double f = 0, k = 0;
		for (int j = 0; j < m; j++)
		if (mass[i][j] == 1)
			f++;
		k = f / n;
		return k;
	}
	int initialization(int **mass, int n, int m)
	{
			
		for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			mass[i][j] = rand() % (2) - 0;
		return 0;
	}
};