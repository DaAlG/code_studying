using namespace std;

#include <iostream>

int n, m;
int arr[1025][1025];
int sum[1025][1025];

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m; // 1<=n<=1024, 1<=m<=100000
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			sum[i][j] += sum[i][j - 1] + arr[i][j];
		}
	}
	int a, b, c, d;
	while (m--) {
		int res = 0;
		cin >> a >> b >> c >> d;
		for (int i = a; i <= c; i++) {
			res += sum[i][d] - sum[i][b-1];
		}
		cout << res << '\n';
	}
	return 0;
}