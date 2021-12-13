using namespace std;
#include <iostream>
#define MAX 500

int n;
int arr[MAX], dp[MAX];
//dp[i] == i��° �ε������� ������ ���� ���� �κ� ������ ����

int main() {
	int tc;;
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		for (int k = 0; k < n; k++) {
			dp[k] = 1;
			for (int i = 0; i < k; i++) {
				if (arr[i] < arr[k])
					dp[k] = max(dp[i] + 1, dp[k]);
			}
		}
		int ans = -1;
		for (int i = 0; i < n; i++)
			ans = max(ans, dp[i]);
		cout << ans << '\n';
	}
}