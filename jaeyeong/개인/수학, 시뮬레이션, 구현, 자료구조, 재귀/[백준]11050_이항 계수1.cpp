using namespace std;
#include <iostream>

int dp[1001][1001];

int main() {
	int n, k;
	cin >> n >> k;
	if (k == 0) {
		cout << "1\n";
		return 0;
	}
	int p = 1, q = 1;
	int answer = 1;
	for (int i = 1, j=n; i <= k; i++, j--) {
		answer *= j;
		answer /= i;
	}
	cout << answer << '\n';
	return 0;
}