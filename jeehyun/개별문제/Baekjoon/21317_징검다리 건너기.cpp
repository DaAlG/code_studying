#include <iostream>
using namespace std;

int n, k;
int energy[21][2];
int dp[21][2];

void init()
{
	dp[1][0] = dp[1][1] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i][1] = 100000;
	}
}

void go(int now, int flag)
{
	if (now == n) return;

	if (now + 1 <= n) { // 작은 점프
		dp[now + 1][flag] = min(dp[now + 1][flag], dp[now][flag] + energy[now][0]);
		go(now + 1, flag);
	}

	if (now + 2 <= n) { // 큰 점프
		dp[now + 2][flag] = min(dp[now + 2][flag], dp[now][flag] + energy[now][1]);
		go(now + 2, flag);
	}

	if (!flag && now + 3 <= n) { // 매우 큰 점프는 한 번만 된다
		dp[now + 3][!flag] = min(dp[now + 3][!flag], dp[now][flag] + k);
		go(now + 3, !flag);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> energy[i][0] >> energy[i][1];
	}
	cin >> k;

	init();
	go(1, 0);

	cout << min(dp[n][0], dp[n][1]);

	return 0;
}
