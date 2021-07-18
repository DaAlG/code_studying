using namespace std;
#include <iostream>
#define MAX 205
#define DIV 100

int n, k;
int a[MAX], dp[MAX][MAX];
//dp[i][j] : i~j 구간의 a[i] 색 통일했을 때 최소 변경 회수

int solve(int l, int r) {
	if (dp[l][r]) return dp[l][r];
	if (r - l <= 1) {
		dp[l][r] = a[l] == a[r] ? 0 : 1; //같다면 뒤집을 필요가 없다.
		return dp[l][r];
	}
	dp[l][r] = MAX;
	for (int i = l; i <= r - 1; i++) {
		int ret = solve(l, i) + solve(i + 1, r) + (a[l] == a[i + 1] ? 0 : 1);
		/*
		* 전체에서 구간을 2개로 나누고 다시 1개로 합칠 때 두 구간의 가장 왼쪽 전구의 색이 다르면 +1
		* (a[l] == a[i + 1] ? 0 : 1)
		*/
		if (dp[l][r] > ret)
			dp[l][r] = ret;
	}
	return dp[l][r];
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout<<solve(0, n - 1)<<'\n';
	return 0;
}