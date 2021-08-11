#include <iostream>
#include <vector>
#define MAX 1 << 6
using namespace std;

int n, q;
int map[MAX][MAX];
int new_map[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void rotate(int x, int y, int size) 
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			new_map[i][j] = map[x + size - j - 1][y + i];
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			map[x + i][y + j] = new_map[i][j];
		}
	}
}

int dfs(int x, int y) 
{
	visited[x][y] = true;

	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) continue;

		if (map[nx][ny] > 0)
			ret += dfs(nx, ny);
	}
	return ret;
}

int sum() {
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result += map[i][j];
		}
	}
	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> q;
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < (1 << n); j++) {
			cin >> map[i][j];
		}
	}
	n = 1 << n;

	for (int i = 0; i < q; i++) {
		int L;
		cin >> L;
		L = 1 << L;

		// 시계방향 회전
		for (int i = 0; i < n; i += L) {
			for (int j = 0; j < n; j += L) {
				rotate(i, j, L);
			}
		}

		// 줄어드는 얼음 찾기
		vector<pair<int, int>> melt;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 0) continue;

				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

					if (map[nx][ny] > 0)
						cnt++;
				}
				
				if (cnt < 3) melt.push_back({ i, j });
			}
		}

		for (pair<int, int> m : melt) {
			map[m.first][m.second]--;
		}
		melt.clear();
	}

	cout << sum() << "\n";

	int maxIce = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] > 0 && !visited[i][j]) {
				maxIce = max(maxIce, dfs(i, j));
			}
		}
	}
	cout << maxIce;

	return 0;
}