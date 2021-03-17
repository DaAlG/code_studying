#include <iostream>

int main() {
	int n, * arr;
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d ", &arr[i]);
	for (int i = (n - 1); i >= 0; i--)
		printf("%d ", arr[i]);
}