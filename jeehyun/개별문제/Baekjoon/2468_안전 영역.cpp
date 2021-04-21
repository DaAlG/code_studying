/*
 * DFS
 * 2468 안전 영역
 */

#include <iostream>
#include <algorithm>
#include <set>
#include <cstring>
#define MAX 100
using namespace std;

int n;
int map[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void dfs(int x, int y, int h) 
{
	if (visited[x][y]) return;

	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if (map[x][y] <= h) continue;

		dfs(nx, ny, h);
	}
}

int main()
{
	cin >> n;
	set<int> height;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			height.insert(map[i][j]);
		}
	}

	int answer = 1; // 물에 잠긴 영역이 없을 경우
	for (auto it = height.begin(); it != height.end(); it++) {
		int h = *it;
		int cnt = 0;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j] && map[i][j] > h) {
					dfs(i, j, h);
					cnt++;
				}
			}
		}
		answer = max(answer, cnt);
	}
	cout << answer;

	return 0;
}