using namespace std;
#include <iostream>

int n, m;
int arr[30][30];

int getRes(int a, int b, int c) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += max(arr[i][a], max(arr[i][b], arr[i][c]));
	}
	return sum;
}
int main() {
	int ans = -1, res = -1;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	if (n > 3) {
		for (int i = 0; i < m; i++) {
			for (int j = i + 1; j < m; j++) {
				for (int k = j + 1; k < m; k++) {
					res = getRes(i, j, k);
					if (res > ans) ans = res;
				}
			}
		}
	}
	else {
		ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				res = max(res, arr[i][j]);
			}
			ans += res;
			res = -1;
		}
	}
	cout << ans << '\n';
}