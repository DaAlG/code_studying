#include <iostream>

int main() {
	int n, result = 0;
	scanf("%d", &n);
	n = 1000 - n;
	result += n / 500;
	n %= 500;
	result += n / 100;
	n %= 100;
	result += n / 50;
	n %= 50;
	result += n / 10;
	n %= 10;
	result += n / 5;
	n %= 5;
	result += n;
	printf("%d", result);
}
