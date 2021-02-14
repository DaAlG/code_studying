#include <iostream>

int main() {
	int n, k, arr[10] = {}, result=0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n; i++) {
		result += k / arr[n - 1 - i];
		k = k % arr[n - 1 - i];
	}
	printf("%d", result);
}
