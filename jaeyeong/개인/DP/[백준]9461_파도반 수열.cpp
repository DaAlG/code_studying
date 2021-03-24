using namespace std;
#include <iostream>

int main() {
	int n, t;
	long long arr[101];
	cin >> t;

	for (int i = 1; i <= 3; i++)
		arr[i] = 1;
	for (int i = 4; i <= 5; i++)
		arr[i] = 2;
	for (int i = 6; i <= 100; i++) {
		arr[i] = arr[i - 5] + arr[i - 1];
	}

	while (t--) {
		cin >> n;

		cout << arr[n] << '\n';
	}
}