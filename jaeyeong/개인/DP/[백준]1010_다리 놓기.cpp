using namespace std;
#include <iostream>

int dp[31][31];

// mCn
int comb(int m, int n) {
	if (m == n || n == 0)
		return 1;
	if (dp[m][n]) return dp[m][n];

	return dp[m][n] = comb(m - 1, n - 1) + comb(m - 1, n);
}
int main() {
	int n, m;
	int t;

	cin >> t;
	while (t--) {
		cin >> n >> m;
		cout << comb(m,n) << '\n';
	}
};