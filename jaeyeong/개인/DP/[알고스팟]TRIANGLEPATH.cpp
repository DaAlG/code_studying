using namespace std;
#include <iostream>
#define MAX 100

int triangle[MAX][MAX], dp[MAX][MAX];
int n;

int solve(int x, int y) {
	if (x == n - 1) return triangle[x][y];
	//메모지에이션
	int& ret = dp[x][y];
	if (ret != -1) return ret;
	return ret = max(solve(x + 1, y), solve(x + 1, y + 1)) + triangle[x][y];
}
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				cin >> triangle[i][j];
				dp[i][j] = -1;
			}
		}
		int ans = solve(0,0);
		cout << ans << '\n';
	}
}