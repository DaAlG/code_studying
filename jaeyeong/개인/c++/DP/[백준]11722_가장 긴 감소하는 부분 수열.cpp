using namespace std;
#include <iostream>
#define MAX 1001

int n, arr[MAX];
int dp[MAX]; //dp[i]=i번째 인덱스에서 끝나는 최장 감소 수열

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int k = 0; k < n; k++) {
		dp[k] = 1;
		for (int i = 0; i < k; i++) {
			if (arr[i] > arr[k])
				dp[k] = max(dp[k], dp[i] + 1);
		}
	}
	int ans = -1;
	for (int i = 0; i < n; i++)
		ans = max(ans, dp[i]);
	cout << ans << '\n';
}