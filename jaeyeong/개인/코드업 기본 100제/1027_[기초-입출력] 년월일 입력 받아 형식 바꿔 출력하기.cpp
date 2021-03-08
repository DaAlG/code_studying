#include <iostream>

int main() {
	int y, m, d;
	scanf("%4d.%2d.%2d", &y, &m, &d);
	printf("%02d-%02d-%04d\n", d, m, y);
}