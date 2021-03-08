#include <iostream>

int main() {
	int n, small, k;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		if (small > k)
			small = k;
	}
	printf("%d", small);
}