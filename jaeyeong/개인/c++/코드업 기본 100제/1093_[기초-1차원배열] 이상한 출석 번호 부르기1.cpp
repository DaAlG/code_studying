#include <iostream>


int main() {
	int arr[24] = { 0 }, n, k;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		arr[k]++;
	}
	for (int i = 1; i <= 23; i++)
		printf("%d ", arr[i]);

}