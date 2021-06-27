using namespace std;
#include <iostream>
#include <string>
#define MAX 1001

int dp[MAX][MAX];
int main() {
	string a, b;
	cin >> a >> b;
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[a.size()][b.size()] << '\n';
}