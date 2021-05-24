/*
 * 그래프
 * 10026 적록색약
 */

#include <iostream>
#include <cstring>
#define MAX 101
using namespace std;

int n;
char map[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void dfs(int x, int y, char color) 
{
	visited[x][y] = true;

	if (map[x][y] == 'G')
		map[x][y] = 'R';

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if (visited[nx][ny] || map[nx][ny] != color) continue;

		dfs(nx, ny, color);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	int answer = 0;

	// 적록색약 X
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				answer++;
				dfs(i, j, map[i][j]);
			}
		}
	}
	cout << answer << ' ';

	answer = 0;
	memset(visited, false, sizeof(visited));

	// 적록색약
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				answer++;
				dfs(i, j, map[i][j]);
			}
		}
	}
	cout << answer << '\n';

	return 0;
}