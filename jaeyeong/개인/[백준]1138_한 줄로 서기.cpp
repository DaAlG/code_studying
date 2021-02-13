#include <iostream>

int main() {
	int n, arr[11] = {}, brr[11] = {}, count=0;
	scanf("%d", &n); //사람 수
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= n; i++) {
			if (brr[i] == 0 && count == arr[j]) {
				brr[i] = j;
				count = 0;
				break;
			}
			else if (brr[i] == 0) count++;
		}
	}

	for (int i = 1; i <= n; i++)
		printf("%d ", brr[i]);
}
