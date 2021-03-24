using namespace std;
#include <iostream>

int main() {
	int n;
	int dp[1010] = {};
	int A[1010] = {};
	int maxv = 0;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> A[i];
	for (int i = 1; i <= n; i++) {
		int minv = 0;
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j]) {
				if (minv < dp[j])
					minv = dp[j];
			}
		}
		dp[i] = minv + 1;
		if (maxv < dp[i])
			maxv = dp[i];
	}
	cout << maxv << '\n';
}