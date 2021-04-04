/*
* DP가 많이 부족한 것 같아서 DP문제를 달리기 시작했다.
* 그래도 이 문젠 고민 많이 해서 근본 해결방법은 정답을 맞췄다.
* 재귀로 시도해서 문제였지.. DP해결법은 다른 사람 코드를 참고했다.
* 그리고 sum구할때 %1000000000 계속 안매겨주니까 틀린 답이 나왔다.
* 다른 문제 풀 때 주의하자
*/
using namespace std;
#include <iostream>

int n;
long dp[10][101] = {0}; //맨끝 수가 행이고 길이가 행.

int main() {
	cin >> n;
	for (int i = 1; i <= 9; i++)
		dp[i][1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[0][i] = dp[1][i - 1];
		dp[9][i] = dp[8][i - 1];
		for (int j = 1; j < 9; j++) {
			dp[j][i] = (dp[j - 1][i - 1] + dp[j + 1][i - 1]) % 1000000000;
		}
	}

	long sum = 0;
	for (int i = 0; i < 10; i++) {
		sum = (sum + dp[i][n]) % 1000000000;
	}
	sum %= 1000000000;
	cout << sum << '\n';
}