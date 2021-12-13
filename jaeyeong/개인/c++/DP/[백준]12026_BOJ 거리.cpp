using namespace std;
#include <iostream>
#include <map>

int dp[1001];
char input[1001];

int main(int argc, char* argv[]) {
	int n;
	map<char, char> m;
	cin >> n;

	m['B'] = 'O';
	m['O'] = 'J';
	m['J'] = 'B';

	for (int i = 1; i <= n; i++)
		cin >> input[i];

	for (int i = 2; i <= n; i++)
		dp[i] = -1;

	dp[1] = 0;

	for (int i = 1; i <= n; i++) {
		char cur = input[i];
		if (dp[i] == -1) continue;
		for (int j = i + 1; j <= n; j++) {
			if (input[j] == m[cur]) {
				if (dp[j] == -1)
					dp[j] = dp[i] + (j - i) * (j - i);
				else
					dp[j] = min(dp[j], dp[i] + ((j - i) * (j - i)));
			}
		}
	}

	cout << dp[n] << '\n';
}