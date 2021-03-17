#include <iostream>
#include <cmath>

int main() {
	int a, r, n;

	scanf("%d %d %d", &a, &r, &n);

	printf("%.lf", a * pow(r, n - 1));
}