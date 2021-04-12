using namespace std;
#include <iostream>
#include <algorithm>

int n;
int house[1000][3];
int dp[1000][3];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			cin >> house[i][j];

	dp[0][0] = house[0][0];
	dp[0][1] = house[0][1];
	dp[0][2] = house[0][2];

	for (int i = 1; i < n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + house[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + house[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + house[i][2];
	}

	sort(dp[n - 1], dp[n - 1] + 3);
	cout << dp[n-1][0]<< '\n';
}