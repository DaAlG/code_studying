/* 브루트포스
 * 14500 테트로미노
 */

#include <iostream>
using namespace std;

int n, m;
int arr[500][500];
bool visited[500][500];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int ans = 0;

void go(int x, int y, int cnt, int sum)
{
	if (cnt == 4) {
		if (ans < sum) ans = sum;
		return;
	}

	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

		if (!visited[nx][ny]) {
			go(nx, ny, cnt + 1, sum + arr[nx][ny]);
			visited[nx][ny] = false;
		}
	}

	visited[x][y] = false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			go(i, j, 0, 0);

			if (j + 2 < m) {
				int temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2];
				if (i - 1 >= 0) { // ㅗ 모양
					int temp2 = temp + arr[i - 1][j + 1];
					if (ans < temp2) ans = temp2;
				}
				if (i + 1 < n) { // ㅜ 모양
					int temp2 = temp + arr[i + 1][j + 1];
					if (ans < temp2) ans = temp2;
				}
			}

			if (i + 2 < n) {
				int temp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j];
				if (j - 1 >= 0) { // ㅓ 모양
					int temp2 = temp + arr[i + 1][j - 1];
					if (ans < temp2) ans = temp2;
				}
				if (j + 1 < m) { // ㅏ 모양
					int temp2 = temp + arr[i + 1][j + 1];
					if (ans < temp2) ans = temp2;
				}
			}
		}
	}
	
	cout << ans;
	return 0;
}