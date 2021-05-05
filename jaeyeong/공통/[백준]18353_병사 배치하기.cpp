using namespace std;
#include <iostream>

int n;
int arr[2000], dp[2000];

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}
	int answer = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	int maxV = -1;
	for (int i = 0; i < n; i++)
		maxV = max(maxV, dp[i]);
	cout << n - maxV << '\n';
}