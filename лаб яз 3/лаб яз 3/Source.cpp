#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
struct str
{
	char reg;
	int flo, roo, ren;
}*k;
int vibor,n;
ifstream fin;
ofstream fout;
void manual()
{
	cin >> n;
	k = new str[n];
	for (int i = 0; i < n; i++)
		cin >> k[i].reg >> k[i].flo >> k[i].roo >> k[i].ren;
}
void out()
{
	int w = 8;
	fin.open("config.cfg");
	fin >> w;
	fin.close();
	for (int i = 0; i < n; i++)
		cout 
		<< "||" <<setw(w) << k[i].reg 
		<< "|" << setw(w) << k[i].flo 
		<< "|" << setw(w) << k[i].roo 
		<< "|" << setw(w) << k[i].ren 
		<< "||" << endl;
}
void save(int q)
{
	if (q == 1)
		;
};
string get_ext(const string& st) {
	size_t pos = st.rfind('.');
	if (pos <= 0) return "";
	return st.substr(pos + 1, string::npos);
}
int main(int argc, char *argv[])
{
	setlocale(LC_ALL,"");
	do {
		cout << "1. Заполнить вручную\n2. Вывод на экран\n3. Сохранить\n4. Загрузить\n5. Фильтрация\n6. Отчет\n7. Выход\n";
		cin >> vibor;
		system("cls");
		cin.clear();
		cin.ignore();
		switch (vibor)
		{
		case 1: manual();
			break;
		case 2: out();
			break;
		case 3:
		{
			char a[20];
			int b;
			cin >> a;

			for (b = 0;a[b] != '\0';b++);
			for (b = b + 1;a[b] != '.'&&b > 0;b--);
			for (b;a[b] != '\0'&&b!=0;b++) cout << a[b];
			//cout << b << endl;
			//get_ext(a);
		}
			//tout();
			break;
		case 4:
			//bout();
			break;
		case 5:
			//tin();
			break;
		case 6:
			//bin();
			break;
		default:
			break;
		}
	} while (vibor != 7);
	delete[]k;
	return 0;
}