#include <iostream>

int main() {
	int n;
	scanf("%X", &n);
	for (int i = 1; i <= 0xf; i++) {
		printf("%X*%X=%X\n", n, i, i * n);
	}
}