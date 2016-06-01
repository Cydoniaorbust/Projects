#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
using namespace std;
void main()
{
	char s[255];
	cin >> s;
	FILE * ptrFile = fopen(s, "r");
	if (ptrFile == NULL) perror("File opening failure!");
	else
	{
		fseek(ptrFile, 0, SEEK_END);
		int size = ftell(ptrFile);
		fclose(ptrFile);
		cout << "File size: " << size << " byte\n";
	}
	system("pause");
}