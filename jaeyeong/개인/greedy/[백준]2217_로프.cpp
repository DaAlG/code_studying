#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, arr[100000] = {}, w;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (max < arr[i] * (n - i)) max = arr[i] * (n - i);
	}
	
	
	printf("%d", max);


}
