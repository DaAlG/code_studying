#include <iostream>

int main() {
	long int a, b;
	scanf("%ld %ld", &a, &b);
	printf("%ld\n%ld\n%ld\n%ld\n%ld\n%.2lf", a + b, a - b, a * b, a / b, a % b, (double)a / (double)b);
}