using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>


int MAX = 100001;

int main() {
	int n, k, temp, min_value;
	int value[100001], coin[100];
	int x;

	cin >> n >> k;

	value[0] = 0;
	for (int i = 1; i <= k; i++)
		value[i] = MAX;

	for (int i = 0; i < n; i++) {
		cin >> coin[i];
		value[coin[i]] = 1;
	}
	sort(coin, coin+n);
	

	for (int i = coin[0]; i <= k; i++) {
		for (int j = 0; j < n; j++) {
			if (value[i] == 1) break;
			if (i - coin[j] < 0) break;
			if(value[i - coin[j]] == MAX) continue;
			value[i] = min(value[i], value[i - coin[j]]+1);
		}
	}
	if (value[k] == MAX) cout << -1 << '\n';
	else cout << value[k] << '\n';
}