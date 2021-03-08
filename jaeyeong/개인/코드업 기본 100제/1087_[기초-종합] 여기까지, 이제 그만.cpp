#include <iostream>

int main() {
	int n, i = 1,sum = 0;

	scanf("%d", &n);
	while (sum<n) {
		sum += i;
		i++;
	}
	printf("%d", sum);
}