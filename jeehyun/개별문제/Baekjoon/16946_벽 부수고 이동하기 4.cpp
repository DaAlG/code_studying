/*
 * 그래프
 * 16946 벽 부수고 이동하기 4
 */

#include <iostream>
#include <set>
#define MAX 1002
using namespace std;

int n, m;
char map[MAX][MAX];
bool visited[MAX][MAX];
int connected[MAX][MAX];
int cnt[MAX * MAX];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool check(int x, int y)
{
	return x >= 0 && y >= 0 && x < n && y < m;
}

void dfs(int k, int x, int y)
{
	visited[x][y] = true;

	// 연결요소 번호
	connected[x][y] = k;
	// 연결요소 안의 요소 개수
	cnt[k]++;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (!check(nx, ny)) continue;
		if (visited[nx][ny] || map[nx][ny] != '0') continue;

		dfs(k, nx, ny);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	int idx = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && map[i][j] == '0') {
				// 연결요소 개수를 구한다
				dfs(idx++, i, j);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '1') {
				set<int> move; // 중복 확인
				int total = 1; // 자신 포함

				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (!check(nx, ny)) continue;

					// 중복되지 않도록 한번만 더한다
					if (!move.count(connected[nx][ny])) {
						move.insert(connected[nx][ny]);
						total += cnt[connected[nx][ny]];
					}
				}

				// 이동할 수 있는 칸의 개수를 10으로 나눈 나머지 출력
				map[i][j] = '0' + total % 10;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << map[i] << '\n';
	}

	return 0;
}