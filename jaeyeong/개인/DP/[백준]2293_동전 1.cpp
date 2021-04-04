using namespace std;
#include <iostream>
#include <algorithm>

int main() {
	int n, k;
	int coin[100], v[10001] = { 0 };
	cin >> n >> k;


	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	sort(coin, coin + n);

	v[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			if (j - coin[i] < 0) break;
			v[j] += v[j - coin[i]];
		}
	}
	cout << v[k] << '\n';
}