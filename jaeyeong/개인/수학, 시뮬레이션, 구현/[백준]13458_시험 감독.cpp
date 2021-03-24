using namespace std;
#include <iostream>

long long arr[1000000];
long long n, b, c, ans = 0;


int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> b >> c;

	for (int i = 0; i < n; i++) {
		ans++;
		arr[i] -= b;
		if (arr[i] <= 0) continue;

		int temp = arr[i] % c;
		ans += arr[i] / c;
		if (temp != 0)
			ans++;
	}

	cout << ans << '\n';
}