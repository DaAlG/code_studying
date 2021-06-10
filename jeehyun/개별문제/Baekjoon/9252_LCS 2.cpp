/*
 * DP
 * 9252 LCS 2
 */

#include <iostream>
#include <string>
#include <algorithm>
#define MAX 1001
using namespace std;

int dp[MAX][MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a, b;
	cin >> a >> b;

	int alen = a.size();
	int blen = b.size();

	a.insert(a.begin(), '0');
	b.insert(b.begin(), '0');


	for (int i = 1; i <= alen; i++) {
		for (int j = 1; j <= blen; j++) {
			if (a[i] == b[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[alen][blen] << '\n';

	string lcs;
	int i = alen;
	int j = blen;

	// 경로 추적
	while (dp[i][j] != 0) {
		// 현재 최대 공통 부분수열의 마지막 부분 찾아가기
		if (dp[i - 1][j] == dp[i][j]) {
			i -= 1;
		}
		else if (dp[i][j - 1] == dp[i][j]) {
			j -= 1;
		}
		else {
			// 같은 값이 없으면 최대 공통 부분수열에 포함되는 문자이므로 해당 문자를 넣고 이동
			lcs += a[i];
			i -= 1;
			j -= 1;
		}
	}
	reverse(lcs.begin(), lcs.end());
	cout << lcs;
	return 0;
}