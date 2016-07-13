#include <cstdio>
int main(int argc, char *argv[])
{
	char s[255];
	scanf("%s", s);
	FILE * f = fopen(s, "r");
	fseek(f, 0, SEEK_END);
	printf("%d byte", ftell(f));
	scanf("%s", s);
	return 0;
}