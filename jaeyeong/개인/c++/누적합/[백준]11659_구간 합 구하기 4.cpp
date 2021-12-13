using namespace std;
#include <iostream>

int n, m;
int arr[100001], sum[100001];
int main() {
	int x, y;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		cout << sum[y] - sum[x] + arr[x] << '\n';
	}
	return 0;
}