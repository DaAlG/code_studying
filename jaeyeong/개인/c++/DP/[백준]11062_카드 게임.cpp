using namespace std;
#include <iostream>
#include <cstring>
#define MAX 1001

int n;
int card[MAX];
int dp[MAX][MAX]; //dp[i][j] : i~j 구간의 최선전략에서 근우 점수

int solve(int l, int r) {
	if (r - l < 0) return 0;
	if (dp[l][r]) return dp[l][r];
	if (r - l <= 1) { //카드 2장 남은 경우
		dp[l][r] = max(card[l], card[r]); // 큰 수를 뽑는 게 늘 최선이다.
		return dp[l][r];
	}
	//왼쪽을 뽑는 경우, 승우가 따라서 왼쪽을 뽑거나 오른쪽을 뽑는 경우 중 더 큰 값
	dp[l][r] = card[l] + min(solve(l + 2, r), solve(l + 1, r - 1));
	//오른쪽은 반대
	dp[l][r] = max(dp[l][r], card[r] + min(solve(l + 1, r - 1), solve(l, r - 2)));
	return dp[l][r];
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		memset(dp, 0, sizeof(dp));
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> card[i];
		cout<<solve(0,n-1)<<'\n';
	}
	return 0;
}