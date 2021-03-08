#include <iostream>

int main() {
	int a, b, c;
	char odd[] = "odd", even[] = "even";
	scanf("%d %d %d", &a, &b, &c);
	printf("%s\n", a % 2 == 0 ? even : odd);
	printf("%s\n", b % 2 == 0 ? even : odd);
	printf("%s\n", c % 2 == 0 ? even : odd);
}