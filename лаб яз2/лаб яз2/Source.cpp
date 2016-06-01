#include <iostream>
#include <fstream>
using namespace std;
struct zapkn {
	char fio[255], street[255];
	int birth, house, flat;
}*zap;
char name[20], name2[20];
int kol, vibor;
ifstream fin;
ofstream fout;
void sort(zapkn *s, int kol)
{
	for (int i = 0;i < kol - 1;i++)
		for (int j = i + 1;j < kol;j++)
			if (strcmp(s[i].fio, s[j].fio)>0)
			{
				s[kol + 1] = s[i];
				s[i] = s[j];
				s[j] = s[kol + 1];
			}
}
void checknread(char *name)
{
	bool l = 0;
	do {
		cout << "Введите имя файла: ";cin >> name;
		fin.open(name);
		if (fin) l = 1;
		else cout << "Не удалось открыть файл! Повторите ввод." << endl;
	} while (!l);
	fin >> kol;
	zap = new zapkn[kol + 2];
	for (int i = 0;i < kol;i++)
		fin >> zap[i].fio >> zap[i].birth >> zap[i].street >> zap[i].house >> zap[i].flat;
	fin.close();
	sort(zap, kol);
}
void outnwrite(char *name2)
{
	cout << "Введите название улицы: ";cin >> zap[kol].street;
	cout << "Введите минимальный и максимальный года: ";cin >> zap[kol].house >> zap[kol].flat;
	cout << "Введите имя файла вывода: ";cin >> name2;
	fout.open(name2);
	for (int i = 0;i < kol;i++)
		if (!strcmp(zap[i].street, zap[kol].street) && ((zap[i].birth >= zap[kol].house&&zap[i].birth <= zap[kol].flat) || (zap[i].birth <= zap[kol].house&&zap[i].birth >= zap[kol].flat)))
		{
			fout << zap[i].fio << endl;
			cout << zap[i].fio << ' ' << zap[i].birth << ' ' << zap[i].street << ' ' << zap[i].house << ' ' << zap[i].flat << endl;
		}
	fout.close();
}
int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "");
	do {
		cout << "1. Файл ввода\n2. Обработка и файл вывода\n3. Выход\n";
		cin >> vibor;
		system("cls");
		switch (vibor)
		{
		case 1:
			checknread(name);
			break;
		case 2:
			outnwrite(name2);
			system("pause");
			break;
		default:
			break;
		}
		system("cls");
	} while (vibor != 3);
	delete[]zap;
	return 0;
}