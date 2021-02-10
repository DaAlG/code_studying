/* Dynamic Programming
 * 10844 쉬운 계단 수
 * 인접한 모든 자리수의 차이가 1이 나는 수를 계단 수라고 함
 * ex) 45656
 * 길이가 N인 계단 수의 개수
 * 정답을 1000000000으로 나눈 나머지 출력
 */

#include <iostream>

using namespace std;

int dp[101][10];
const int mod = 1000000000;

int calc(int n)
{
	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}

	// i는 숫자의 길이, j는 어떤 수의 끝 숫자
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) // 0은 1만 허용됨
				dp[i][j] = dp[i - 1][j + 1] % mod;
			else if (j == 9) // 9는 8만 허용됨
				dp[i][j] = dp[i - 1][j - 1] % mod;
			else // 1~8은 +1, -1 허용
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
		}
	}

	long long sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum += dp[n][i];
	}

	return sum % mod;
}

int main()
{
	int N;
	cin >> N;
	cout << calc(N) << endl;
	return 0;
}