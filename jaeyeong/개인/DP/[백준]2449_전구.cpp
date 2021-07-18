using namespace std;
#include <iostream>
#define MAX 205
#define DIV 100

int n, k;
int a[MAX], dp[MAX][MAX];
//dp[i][j] : i~j ������ a[i] �� �������� �� �ּ� ���� ȸ��

int solve(int l, int r) {
	if (dp[l][r]) return dp[l][r];
	if (r - l <= 1) {
		dp[l][r] = a[l] == a[r] ? 0 : 1; //���ٸ� ������ �ʿ䰡 ����.
		return dp[l][r];
	}
	dp[l][r] = MAX;
	for (int i = l; i <= r - 1; i++) {
		int ret = solve(l, i) + solve(i + 1, r) + (a[l] == a[i + 1] ? 0 : 1);
		/*
		* ��ü���� ������ 2���� ������ �ٽ� 1���� ��ĥ �� �� ������ ���� ���� ������ ���� �ٸ��� +1
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