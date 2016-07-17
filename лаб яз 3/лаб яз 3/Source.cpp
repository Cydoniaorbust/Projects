#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
struct str
{
	string region;
	int floor, rooms, rent;
}*k;
int n; // size of mas
string s;// filename
ifstream fin; ofstream fout;
void manual()
{
	cin >> n; k = new str[n];
	for (int i = 0; i < n; i++)
		cin >> k[i].region >> k[i].floor >> k[i].rooms >> k[i].rent;
}
void out()
{
	int w = 8;
	fin.open("config.cfg"); fin >> w; fin.close();
	for (int i = 0; i < n; i++)
		cout 
		<< "||" <<setw(w) << k[i].region 
		<< "|" << setw(w) << k[i].floor 
		<< "|" << setw(w) << k[i].rooms 
		<< "|" << setw(w) << k[i].rent 
		<< "||" << endl;
}
string get_name()
{
	size_t p;
	do	{
		cin >> s;
		p = s.rfind('.');
		if (p > s.length()) cout << "Invalid filename!";
	} while (p > s.length());
	return s.substr(p + 1, string::npos);
}
void save()
{
	if (get_name() == "txt") {
		fout.open(s);
		for (int i = 0;i < n;i++)
			fout << k[i].region << " " << k[i].floor << " " << k[i].rooms << " " << k[i].rent << endl;
	}
	else if (get_name() == "bin") {
		fout.open(s, ios::binary);
		fout.write((char*)&n, sizeof(n));
		for (int i = 0;i < n;i++)
		{
			fout.write((char*)&k[i].region, sizeof(k[i].region));
			fout.write((char*)&k[i].floor, sizeof(k[i].floor));
			fout.write((char*)&k[i].rooms, sizeof(k[i].rooms));
			fout.write((char*)&k[i].rent, sizeof(k[i].rent));
		}
	}
	else cout << "Not a bin or txt file!" << endl;
	fout.close();
}
void load() 
{
	if (get_name() == "txt") {
		fin.open(s);
		while (!EOF)

		for (int i = 0;i < n;i++)
			fin >> k[i].region >> k[i].floor >> k[i].rooms >> k[i].rent;
	}
	else if (get_name() == "bin") {
		fin.open(s, ios::binary);
		fin.read((char*)&n, sizeof(n));
		k = new str[n];
		for (int i = 0;i < n;i++)
		{
			fin.read((char*)&k[i].region, sizeof(k[i].region));
			fin.read((char*)&k[i].floor, sizeof(k[i].floor));
			fin.read((char*)&k[i].rooms, sizeof(k[i].rooms));
			fin.read((char*)&k[i].rent, sizeof(k[i].rent));
		}
	}
	else cout << "Not a bin or txt file!" << endl;
	fin.close();
}
void filtr() 
{

}
void report() 
{

}
int main(int argc, char *argv[])
{
	setlocale(LC_ALL,"");
	int choice;
	do {
		cout << "1. Заполнить вручную\n2. Вывод на экран\n3. Сохранить\n4. Загрузить\n5. Фильтрация\n6. Отчет\n7. Выход\n";
		cin >> choice;
		system("cls");
		cin.clear();
		cin.ignore();
		switch (choice)
		{
		case 1: manual();
			break;
		case 2: out();
			break;
		case 3:	save();
			break;
		case 4:	load();
			break;
		case 5: filtr();
			break;
		case 6: report();
			break;
		default:
			break;
		}
	} while (choice != 7);
	delete[]k;
	return 0;
}