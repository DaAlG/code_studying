#include <iostream>

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	a = a > b ? b : a;
	printf("%d", a >c ? c : a);
}