#include <iostream>
int main() {
	char n,a='a';
	scanf("%c", &n);
	do
	{
		printf("%c\n", a);
	} while (a++ != n);
}