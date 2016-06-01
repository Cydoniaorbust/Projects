#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
class biba
{
private:
public:
	void Selection_proportional(int **mas, int str, int stl)//,int massss)
	{
		srand((unsigned int)time(NULL));
		double *norm_fit, *p, e, sum = 0, max_fit, min_fit, p_s = 0;
		p = new double[str];
		norm_fit = new double[str];

		for (int i = 0; i < str; i++)
		{
			int f = 0, k = 0;
			for (int j = 0; j < stl; j++)

			{
				if (mas[i][j] == 1)
					f++;
				
				norm_fit[i] = f;

			}
			cout << f << '\t';

			sum = sum + f;

		}cout << endl;
		cout << "sum=" << sum << endl;



		max_fit = norm_fit[0];
		min_fit = norm_fit[0];
		for (int i = 0; i < str; i++)
		{
			if (norm_fit[i]<min_fit)
			{
				min_fit = norm_fit[i];
			}
			if (norm_fit[i]>max_fit)
			{
				max_fit = norm_fit[i];
			}
		}
		cout << "maxf=" << max_fit << endl;
		cout << "minf=" << min_fit << endl;

		/*for (int i = 0; i < str; i++)
		{
		p[i] = (norm_fit[i] - min_fit) / (max_fit - min_fit);
		cout << p[i] << "\t";

		}cout << endl;*/
		for (int i = 0; i < str; i++)
		{
			p[i] = (norm_fit[i] - min_fit) / (max_fit - min_fit);
			p[i] = p[i] / sum;
			cout << p[i] << "\t";
		}cout << endl;

		cout << p[0] << '\t';
		for (int i = 1; i < str; i++)
		{
			p[i] = p[i - 1] + p[i];
			cout << p[i] << '\t';
		}cout << endl;

		//while (p_s < str * 2)
		//{
			//double P;
		//	P = ;
		//	cout << "p="<< P <<endl;


		//}



	}
	void Selection_Tournament(int**mas, int str, int stl, int **masss)
	{
		srand((unsigned int)time(NULL));

		int tournament, **m, E[2], biba, pipa, i1, i2, i3, i4, i5, i6, i7;
		cout << "������� ������ ������� (�� 2 �� " << str << ") :" << endl;
		do{ cin >> tournament; } while (tournament > str&& tournament < 2);
		m = new int*[2]; for (i1 = 0; i1 < 2; i1++)m[i1] = new int[tournament];
		
		
			for (i2 = 0; i2 < str; i2++)
			{
				biba = 0;
				pipa = tournament - 1;
				for (i3 = 0; i3 < tournament; i3++)
				{
					int a;
					do
					{
						a = 0;
						int k = rand() % (str);
						m[0][i3] = k;
						for (i4 = 0; i4 != i3; i4++)
						if (m[0][i3] == m[0][i4])
							a = 1;
					} while (a == 1);

					int f = 0;
					cout << "������������ ������ : " << m[0][i3] + 1 << endl;
					for (i5 = 0; i5 < stl; i5++)
					if (mas[m[0][i3]][i5] == 1)
						f++;
					m[1][i3] = f;
					cout << "����������� : " << m[1][i3] << endl;
				}
				for (int j = 0; j < tournament; j++)
				for (i6 = 0; i6 < pipa - j; i6++)
				if (m[1][i6] > m[1][i6 + 1])
				{
					E[0] = m[0][i6]; E[1] = m[1][i6];
					m[0][i6] = m[0][i6 + 1]; m[1][i6] = m[1][i6 + 1];
					m[0][i6 + 1] = E[0]; m[1][i6 + 1] = E[1];
				}
				for (int k = 0; k < 2; k++)
				{
					for (int l = 0; l < tournament; l++)
					if (k == 0)
						cout << m[k][l] + 1 << "\t";
					else
						cout << m[k][l] << "\t";
					cout << endl;

				}
				cout << "***********************************************" << endl;
				while (m[1][pipa] == m[1][pipa - 1])
				{
					biba++;
					pipa--;
				}
				if (biba > 0)
				{
					for (i7 = 0; i7 < stl; i7++)
						masss[i2][i7] = mas[m[0][tournament - 1 - rand() % (biba)]][i7];
				}
				else
				{
					for (i7 = 0; i7 < stl; i7++)
					{
						masss[i2][i7] = mas[m[0][pipa]][i7];
					}
				}
			}
		
	}
	void Weak_mutation(int**mas, int str, int stl)
	{
		cout << "*************************" << endl << "������� ������";
		int Q;
		srand((unsigned int)time(NULL));

		for (int i = 0; i < str; i++)
		{

			for (int j = 0; j < stl; j++)
			{
				Q = rand() % (100);

				if (Q < 1)
				{
					if (mas[i][j] == 1)
						mas[i][j] = 0;
					else mas[i][j] = 1;
				}
			}
		}
	}
	void Average_mutation(int**mas, int str, int stl)
	{
		cout << "*************************" << endl << "������� �������";
		int Q;
		srand((unsigned int)time(NULL));

		for (int i = 0; i < str; i++)
		{

			for (int j = 0; j < stl; j++)
			{
				Q = rand() % (100);

				if (Q < 10)
				{
					if (mas[i][j] == 1)
						mas[i][j] = 0;
					else mas[i][j] = 1;
				}
			}
		}
	}
	void Strong_mutation(int**mas, int str, int stl)
	{
		cout << "*************************" << endl << "������� �������";
		int Q;
		srand((unsigned int)time(NULL));

		for (int i = 0; i < str; i++)
		{

			for (int j = 0; j < stl; j++)
			{
				Q = rand() % (100);

				if (Q < 50)
				{
					if (mas[i][j] == 1)
						mas[i][j] = 0;
					else mas[i][j] = 1;
				}
			}
		}
	}
	void Skreshivanie_ravnomernoe(int**mas, int str, int stl, int **mass)
	{
		cout << "*************************" << endl << "����������� �����������" << endl;
		srand((unsigned int)time(NULL));
		int k, l, j, a, e = 0, RA;
		for (a = 0; a != str; a += 1)
		{

			do
			{

				RA = rand() % (2) - 0;
				k = rand() % (str);
				l = rand() % (str);

			} while (k == l);
			cout << k << l << endl;

			j = 0;
			for (int i = 0; i < stl; i++)
			{
				if (mas[k][i] == 1 && mas[l][i] == 1)
					mass[e][j] = 1;
				else if (mas[k][i] == 0 && mas[l][i] == 0)
					mass[e][j] = 0;
				else mass[e][j] = RA;
				j++;
			}e++;
		}
	}
	void Prigodnost(int**mas, int str, int stl)
	{

		for (int i = 0; i < str; i++)
		{
			int f = 0, k = 0;
			for (int j = 0; j < stl; j++)

			if (mas[i][j] == 1)
				f++;
			k = f;


			cout << "����������� �������� � " << i + 1 << " : " << k << endl;
		}
	}
	void message()
	{
		cout << "������� ��������� ������" << endl;

	}
	void vivod(int **mass, int str, int stl)
	{
		cout << endl << "-------------------------" << endl;
		for (int i = 0; i <str; i++)
		{
			for (int j = 0; j < stl; j++)
				cout << mass[i][j] << "\t";
			cout << endl;
		}
		cout << "-------------------------" << endl;


	}
	void initialization(int **mass, int str, int stl)
	{
		srand((unsigned int)time(NULL));
		cout << endl;
		for (int i = 0; i < str; i++)
		for (int j = 0; j < stl; j++)
			mass[i][j] = rand() % (2) - 0;
	}
};
int main()
{
	setlocale(0, "");
	int str, stl, str2, stl2;

	biba objMessage;
	objMessage.message();
	cout << "����������� �����" << endl;
	cin >> str;
	cout << "����������� ���������" << endl;
	cin >> stl;

	int **mas, **mass, **masss, **massss;

	mas = new int*[str];
	mass = new int*[str];
	masss = new int*[str];
	massss = new int*[str];

	for (int i = 0; i < str; i++)
	{
		mas[i] = new int[stl];
		mass[i] = new int[stl];
		masss[i] = new int[stl];
		massss[i] = new int[stl];
	}

	objMessage.initialization(mas, str, stl);
	objMessage.vivod(mas, str, stl);
	objMessage.Prigodnost(mas, str, stl);

	objMessage.Skreshivanie_ravnomernoe(mas, str, stl, mass);
	objMessage.vivod(mass, str, stl);
	objMessage.Prigodnost(mass, str, stl);

	objMessage.Strong_mutation(mas, str, stl);//�������� ���������� ������ ������ ���
	objMessage.vivod(mas, str, stl);
	objMessage.Prigodnost(mas, str, stl);

	objMessage.Average_mutation(mas, str, stl);
	objMessage.vivod(mas, str, stl);
	objMessage.Prigodnost(mas, str, stl);

	objMessage.Weak_mutation(mas, str, stl);
	objMessage.vivod(mas, str, stl);
	objMessage.Prigodnost(mas, str, stl);

	objMessage.Selection_Tournament(mas, str, stl,masss);
	objMessage.vivod(masss, str, stl);
	objMessage.Prigodnost(masss, str, stl);

	objMessage.Selection_proportional(mas, str, stl);

	for (int i = 0; i <str; i++)
		delete mas[i];
	delete[]mas;
	for (int i = 0; i < str; i++)
		delete mass[i];
	delete[]mass;
	for (int i = 0; i <str; i++)
		delete masss[i];
	delete[]masss;

	system("pause");
	return 0;
}