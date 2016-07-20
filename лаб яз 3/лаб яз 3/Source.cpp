#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
struct str {
	char region[20];
	int floor, rooms, rent;
}*k, x;
int choice, n; // size of mas
string s;// filename
ifstream fin; ofstream fout;
string get_name()
{
	size_t p;
	do { cin >> s; p = s.rfind('.'); if (p > s.length()) cout << "Invalid filename!"<<endl; } while (p > s.length());
	return s.substr(p + 1, string::npos);
}
void filesize(int a)
{
	if (a == 0) {
		char *c = new char[35]; int i = 0;
		fin.open(s); for (i;!fin.eof();i++) fin.getline(c, 35, '\n'); n = i - 1; fin.close();
		delete[] c;
	}
	else {
		fin.open(s, ios::binary); fin.seekg(0, fin.end); n = fin.tellg() / 32; fin.seekg(0, fin.beg);
	}
}
int increment(int *inc, int n)
{
	int p1, p2, p3, s;
	p1 = p2 = p3 = 1;
	s = -1;
	do {
		if (++s % 2)
			inc[s] = 8 * p1 - 6 * p2 + 1;
		else {
			inc[s] = 9 * p1 - 9 * p3 + 1;
			p2 *= 2;
			p3 *= 2;
		}
		p1 *= 2;
	} while (3 * inc[s] < n);
	return s > 0 ? --s : 0;
}
void shell(int *&m)
{
	int inc, i, j, seq[40], s;
	s = increment(seq, n);
	while (s >= 0) {
		inc = seq[s--];
		for (i = inc; i < n; i++) {
			x = k[i];
			int t = m[i];
			for (j = i - inc; (j >= 0) && (m[j] > t); j -= inc)
			{
				k[j + inc] = k[j];
				m[j + inc] = m[j];
			}
			k[j + inc] = x;
			m[j + inc] = t;
		}
	}
}
void shell(char **&m1)
{
	int inc, i, j, seq[40], s;
	s = increment(seq, n);
	while (s >= 0) {
		inc = seq[s--];
		for (i = inc; i < n; i++) {
			x = k[i];
			char *t = m1[i];
			for (j = i - inc; (j >= 0) && (strcmp(m1[j], t)); j -= inc)
			{
				k[j + inc] = k[j];
				m1[j + inc] = m1[j];
			}
			k[j + inc] = x;
			m1[j + inc] = t;
			for (int r = 0;r < n;r++)
				cout << k[r].region << " ";
			cout << endl;
		}
	}
}
void bubble(int *&m)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (m[j] > m[j + 1])
			{
				swap(k[j], k[j + 1]);
				swap(m[j], m[j + 1]);
			}
}
void bubble(char **&m1)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (strcmp(m1[j] , m1[j+1]))
			{
				swap(k[j], k[j + 1]);
				swap(m1[j], m1[j + 1]);
			}
}

void manual()
{
	cin >> n; k = new str[n];
	for (int i = 0; i < n; i++)	cin >> k[i].region >> k[i].floor >> k[i].rooms >> k[i].rent;
}
void out()
{
	int w = 8;
	fin.open("config.cfg"); fin >> w; fin.close();
	for (int i = 0; i < n; i++)
		cout << endl << "||"
		<< setw(w) << k[i].region << "|"
		<< setw(w) << k[i].floor << "|"
		<< setw(w) << k[i].rooms << "|"
		<< setw(w) << k[i].rent << "||";
	cout << endl;
}
void save()
{
	string f = get_name();
	if (f == "txt") {
		fout.open(s);
		for (int i = 0;i < n;i++)	fout << k[i].region << " " << k[i].floor << " " << k[i].rooms << " " << k[i].rent << endl;
	}
	else if (f == "bin") {
		fout.open(s, ios::binary);
		for (int i = 0;i < n;i++) {
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
	string f = get_name();
	if (f == "txt") {
		filesize(0); k = new str[n]; fin.open(s);
		for (int i = 0;i < n;i++) fin >> k[i].region >> k[i].floor >> k[i].rooms >> k[i].rent;
	}
	else if (f == "bin") {
		filesize(1); k = new str[n]; fin.open(s, ios::binary);
		for (int i = 0;i < n;i++) {
			fin.read((char*)&k[i].region, sizeof(k[i].region));
			fin.read((char*)&k[i].floor, sizeof(k[i].floor));
			fin.read((char*)&k[i].rooms, sizeof(k[i].rooms));
			fin.read((char*)&k[i].rent, sizeof(k[i].rent));
		}
	}
	else cout << "Not a bin or txt file!" << endl;
	fin.close();
}
void sort()
{
	char **m1 = NULL;
	int *m = NULL;
	do {
		cout << "Choose field:\n1. Region\n2. Floor\n3. Rooms\n4. Rent\n";
		cin >> choice;
		system("cls");
		cin.clear();
		cin.ignore();
		switch (choice)
		{
		case 1:
			m1 = new char*[n];
			for (int i = 0;i < n;i++)
				m1[i] = k[i].region;
			break;
		case 2:
			m = new int[n];
			for (int i = 0;i < n;i++)
				m[i] = k[i].floor;
			break;
		case 3:
			m = new int[n];
			for (int i = 0;i < n;i++)
				m[i] = k[i].rooms;
			break;
		case 4:
			m = new int[n];
			for (int i = 0;i < n;i++)
				m[i] = k[i].rent;
			break;
		default:
			break;
		}
	} while (choice != 1 && choice != 2 && choice != 3 && choice != 4);
	do {
		cout << "Choose sort method:\n1. Shell\n2. Bubble\n";
		cin >> choice;
		system("cls");
		cin.clear();
		cin.ignore();
		switch (choice)
		{
		case 1:
			if (m != NULL) shell(m);
			else shell(m1);
			break;
		case 2:
			if (m != NULL) bubble(m);
			else bubble(m1);
			break;
		default:
			break;
		}
	} while (choice != 1 && choice != 2);
	delete[]m;
	delete[]m1;
}
void filter()
{

}
void report()
{

}
int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "");
	do {
		cout << "1. Заполнить вручную\n2. Вывод на экран\n3. Сохранить\n4. Загрузить\n5. Сортировка\n6. Фильтрация\n7. Отчет\n8. Выход\n";
		cin >> choice; system("cls"); cin.clear(); cin.ignore();
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
		case 5: sort();
			break;
		case 6: filter();
			break;
		case 7: report();
			break;
		default:
			break;
		}
	} while (choice != 8);
	delete[]k;
	return 0;
}