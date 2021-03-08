#include <iostream>

int main() {
	int n, sum=0, i;
	scanf("%d", &n);
	for (i = 1; sum < n; i++) {
		sum += i;
	}
	printf("%d", --i);
}