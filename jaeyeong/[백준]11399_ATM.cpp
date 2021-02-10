#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, arr[1000] = {}, result=0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);

	int m = n;
	for (int i = 0; i < n; i++) {
		result += arr[i] * m;
		m -= 1;
	}

	printf("%d", result);
}