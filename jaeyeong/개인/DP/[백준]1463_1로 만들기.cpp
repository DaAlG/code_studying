//100%에서 틀렸었는데 1넣었을 때 이상한 값이 나와서 그랬다... 예외를 잘 체크할 수 있는 사람이 되자 ㅜ
using namespace std;
#include <iostream>
#define MAX 1000001

int dp[MAX][3];

int getMin(int k) {
	int minV = 0x3f3f3f3f;
	for (int i = 0; i < 3; i++) {
		if (dp[k][i] < minV && dp[k][i]!=0) minV = dp[k][i];
	}
	return minV;
}

int main() {
	int n;
	cin >> n;

	if (n == 1) {
		cout << 0 << '\n';
		return 0;
	}

	dp[2][0] = 1; // -=1
	dp[2][1] = 1; // /=2
	dp[3][2] = 1; // /=3

	for (int i = 4; i <= n; i++) {
		if (i % 2 == 0)
			dp[i][1] = getMin(i/2) + 1;
		if (i % 3 == 0)
			dp[i][2] = getMin(i/3) + 1;
		dp[i][0] = getMin(i - 1) + 1;
	}
	cout << getMin(n) << '\n';
}