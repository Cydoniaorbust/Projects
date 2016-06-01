#include <iostream>
int bgst_grd, ost;
using namespace std;
int init()
{
	int i;
	do {
		cout << "Введите наибольший порядок многочлена: ";
		cin >> bgst_grd;
		if (bgst_grd > 10 || bgst_grd < 2)
			cout << "Многочлен слишком велик/мал!\nЗадайте другое значение.\n";
	} while (bgst_grd > 10 || bgst_grd < 2);
	return i = bgst_grd;
}
int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "");
	int q1 = init();
	int *poly = new int[bgst_grd + 1];					//исходный полином для каждой итерации
	cout << "Введите коэффициенты:\n";
	for (int i = 0;i < bgst_grd + 1;i++)
	{
		cout << "x^" << i << ":";
		cin >> poly[i];
	}

	if (q1 > 2)
	{
		int *newpoly = new int[bgst_grd + 1];					//конечный полином для каждой итерации
		int **exp_rt = new int*[bgst_grd - 1];					//массив корней
		for (int i = 0;i < bgst_grd - 1;i++)
			exp_rt[i] = new int[50];

		for (int i = bgst_grd;i > 0;i--)
		{
			newpoly[i] = 0;
			cout << "(" << poly[i] << "*x^" << i << ") + ";
		}
		cout << "(" << poly[0] << ")\n";

		int rt_nmb, nmb_rts = bgst_grd - 2, next;			//текущий корень, общее кол-во, следующий в очереди
		for (int j = 0;j < nmb_rts;j++)							//j прокрутится от 0 до 8 раз
		{
			rt_nmb = 0;
			if (abs(poly[bgst_grd]) == 1)
			{
				next = 0;
				for (int i = 1;i < abs(poly[0]) + 1;i++)
					if (abs(poly[0]) % i == 0)
					{
						exp_rt[j][next] = i;
						next++;
					}
			}
			else
			{
				cout << "stop";
				system("pause");
			}
			while (rt_nmb <= nmb_rts)								//пока мы не переберем все корни
			{
				newpoly[bgst_grd] = 0;
				for (int i = bgst_grd;i > -1;i--)				//* от 10 до 0 (11 раз) -- верно
				{
					newpoly[i] *= exp_rt[j][rt_nmb];
					newpoly[i] += poly[i];
					if (i != 0)
						newpoly[i - 1] = newpoly[i];
					else
					{
						exp_rt[nmb_rts][j] = exp_rt[j][rt_nmb];
						if (newpoly[i] == 0)
							rt_nmb = nmb_rts + 1;				//выйти из цикла
						else
							if (exp_rt[j][rt_nmb] < 0) rt_nmb++;
							else exp_rt[j][rt_nmb] *= -1;
					}
				}
			}

			for (int i = 0;i < j + 1;i++)
				cout << "(x -(" << exp_rt[nmb_rts][i] << ")) * ";
			if (j + 1 != nmb_rts)
			{
				cout << "(";
				for (int i = bgst_grd;i > 0;i--)
				{
					cout << "(" << newpoly[i] << "*x^" << i - 1 << ") + ";
					poly[i - 1] = newpoly[i];
					newpoly[i] = 0;
				}
				cout << "(" << newpoly[0] << "))\n";
			}
			else 
			{
				for (int i = bgst_grd;i > 0;i--)
					poly[i - 1] = newpoly[i];
				ost = newpoly[0];
				delete[]newpoly;
				for (int i = 0;i<nmb_rts + 1;i++)
					delete exp_rt[i];
				delete[]exp_rt;
			}
			bgst_grd--;
		}
	}
	double disc = pow(poly[1], 2) - 4 * poly[2] * poly[0];
	if (disc > 0)
	{
		double c = pow(disc, 0.5);
		cout << c << endl;
		double a = (-1 * poly[1] + pow(disc, 0.5)) ;
		cout << a<<endl;
		double b = a / (2 * poly[2]);
		cout << b << endl;
		cout << "(x -(" << (-1 * poly[1] + pow(disc, 0.5)) / (2 * poly[2]) << "))*(x -(" << (-1 * poly[1] - pow(disc, 0.5)) / (2 * poly[2]) << "))";
	}
	if (disc < 0)
	{
		cout << "(";
		if (q1 > 2) 
		{
			for (int i = bgst_grd;i > -1;i--)
				cout << "(" << poly[i] << "*x^" << i << ") + ";

			cout << "(" << ost << "))\n";
		}
		else 
		{
			for (int i = bgst_grd;i > 0;i--)
				cout << "(" << poly[i] << "*x^" << i << ") + ";
			cout << "(" << poly[0] << "))\n";
		}
	}
	if (disc == 0)
		cout << "(x -(" << (-1 * poly[1]) / 2 * poly[2] << "))^2\n";

	delete[]poly;
	system("pause");
	return 0;
}