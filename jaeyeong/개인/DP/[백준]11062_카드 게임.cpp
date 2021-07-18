using namespace std;
#include <iostream>
#include <cstring>
#define MAX 1001

int n;
int card[MAX];
int dp[MAX][MAX]; //dp[i][j] : i~j ������ �ּ��������� �ٿ� ����

int solve(int l, int r) {
	if (r - l < 0) return 0;
	if (dp[l][r]) return dp[l][r];
	if (r - l <= 1) { //ī�� 2�� ���� ���
		dp[l][r] = max(card[l], card[r]); // ū ���� �̴� �� �� �ּ��̴�.
		return dp[l][r];
	}
	//������ �̴� ���, �¿찡 ���� ������ �̰ų� �������� �̴� ��� �� �� ū ��
	dp[l][r] = card[l] + min(solve(l + 2, r), solve(l + 1, r - 1));
	//�������� �ݴ�
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