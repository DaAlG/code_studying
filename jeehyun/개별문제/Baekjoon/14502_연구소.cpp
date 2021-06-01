/*
 * 그래프
 * 14502 연구소
 */

#include <iostream>
#include <queue>
#include <cstring>
#define MAX 8
using namespace std;

int n, m;
int map[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int bfs(vector<pair<int, int>> &virus)
{
	memset(visited, false, sizeof(visited));

	queue<pair<int, int>> q;
	for (int i = 0; i < virus.size(); i++) {
		int x = virus[i].first;
		int y = virus[i].second;
		q.push({ x, y });
		visited[x][y] = true;
	}

	// 바이러스가 확산됨
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (visited[nx][ny] || map[nx][ny] == 1) continue;

			visited[nx][ny] = true;
			q.push({ nx, ny });
		}
	}

	int cnt = 0; // 안전 영역 크기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && map[i][j] == 0)
				cnt++;
		}
	}

	return cnt;
}

int go(vector<pair<int, int>> &virus, int x, int y, int cnt) 
{
	// 벽 3개를 세웠다면
	if (cnt == 3) {
		// 바이러스가 퍼질 수 없는 안전 영역 크기를 구한다
		return bfs(virus);
	}

	int maxArea = 0;
	for (int i = x; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				// 벽을 세운다
				map[i][j] = 1;
				
				maxArea = max(maxArea, go(virus, i, j, cnt + 1));
				
				// 원래대로 되돌린다
				map[i][j] = 0;
			}
		}
	}

	return maxArea;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	vector<pair<int, int>> virus;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				virus.push_back({i, j});
		}
	}

	cout << go(virus, 0, 0, 0);

	return 0;
}