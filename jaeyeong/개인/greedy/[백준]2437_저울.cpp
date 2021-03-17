#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	int target = 1, n;
	int arr[1001] = {};

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		if (target < arr[i]) break;
		target += arr[i];
	}

	cout << target;

	return 0;
}