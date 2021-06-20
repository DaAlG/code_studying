/*
 * 백트래킹
 * 1248 맞춰봐
 */

#include <iostream>
using namespace std;

int n;
char s[11][11];
int a[11];
int sum[11];

bool possible(int k)
{
	for (int i = 1; i < k; i++) {
		if (s[i][k] == '+' && sum[k] - sum[i - 1] <= 0) return false;
		if (s[i][k] == '-' && sum[k] - sum[i - 1] >= 0) return false;
		if (s[i][k] == '0' && sum[k] - sum[i - 1]) return false;
	}
	return true;
}

void go(int k)
{
	if (k > n) {
		for (int i = 1; i <= n; i++) {
			cout << a[i] << ' ';
		}
		exit(0);
	}

	if (s[k][k] == '0') {
		a[k] = 0;
		sum[k] = sum[k - 1];
		go(k + 1);
	}
	else {
		int sign = s[k][k] == '-' ? -1 : 1;
		for (int i = 1; i <= 10; i++) {
			a[k] = sign * i;
			sum[k] = sum[k - 1] + a[k];

			if (possible(k))
				go(k + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			cin >> s[i][j];
		}
	}

	go(1);

	return 0;
}