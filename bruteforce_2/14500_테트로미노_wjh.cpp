#include <iostream>

using namespace std;

int a[500][500];
bool c[500][500];
int n, m;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int ans = 0;

void go(int x, int y, int sum, int cnt) {
	if (cnt == 4) {
		if (ans < sum) ans = sum;
		return;
	}

	// 범위 벗어남
	if (x < 0 || x >= n || y < 0 || y >= m) return;
	// 재방문
	if (c[x][y]) return;

	c[x][y] = true;
	for (int k = 0; k < 4; k++) {
		go(x + dx[k], y + dy[k], sum + a[x][y], cnt + 1);
	}
	c[x][y] = false;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			go(i, j, 0, 0); // 이동
			if (j + 2 < m) {
				int temp = a[i][j] + a[i][j + 1] + a[i][j + 2];
				if (i - 1 >= 0) {
					int temp2 = temp + a[i-1][j+1];
					if (ans < temp2) ans = temp2;
				}
				if (i + 1 < n) {
					int temp2 = temp + a[i + 1][j + 1];
					if (ans < temp2) ans = temp2;
				}
			}
			if (i + 2 < n) {
				int temp = a[i][j] + a[i + 1][j] + a[i + 2][j];
				if (j + 1 < m) {
					int temp2 = temp + a[i + 1][j + 1];
					if (ans < temp2) ans = temp2;
				}
				if (j - 1 >= 0) {
					int temp2 = temp + a[i + 1][j - 1];
					if (ans < temp2) ans = temp2;
				}
			}
		}
	}

	cout << ans << endl;
	return 0;
}