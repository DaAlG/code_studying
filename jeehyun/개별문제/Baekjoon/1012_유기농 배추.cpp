/*
 * DFS
 * 1012 유기농 배추
 */

#include <iostream>
#include <cstring>
#define MAX 50
using namespace std;

int n, m;
int map[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void dfs(int x, int y)
{
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

		if (!visited[nx][ny] && map[nx][ny]) {
			dfs(nx, ny);
		}
	}	
}

int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int k;
		cin >> n >> m >> k;

		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));

		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			map[x][y] = 1;
		}

		int answer = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i][j] && map[i][j]) {
					answer++;
					dfs(i, j);
				}
			}
		}

		cout << answer << '\n';
	}
	return 0;
}