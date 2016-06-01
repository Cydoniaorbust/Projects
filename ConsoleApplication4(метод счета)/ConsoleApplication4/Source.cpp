#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Russian");
	for (int i = 10; i < 20; i++)
	{
		for (int j = i; j < 20; j++)
			cout << i*j << " = " <<

			(i / 10)*(j / 10) * 100 + 
			((i % 10)*(j / 10) + (i / 10)*(j % 10)) * 10 + 
			(i % 10)*(j % 10) 
			
			<< endl;
		cout << "------------" << endl;
	}
	system("pause");
	return 0;
}