/*
 * 브루트포스
 * 16948 데스 나이트
 */

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAX 200
using namespace std;

int dist[MAX][MAX];

int dx[] = { -2, -2, 0, 0, 2, 2 };
int dy[] = { -1, 1, -2, 2, -1, 1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	pair<int, int> p[2];
	for (int i = 0; i < 2; i++) {
		cin >> p[i].first >> p[i].second;
	}

	queue<pair<int, int>> q;
	q.push(p[0]);
	memset(dist, -1, sizeof(dist));
	dist[p[0].first][p[0].second] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == p[1].first && y == p[1].second)
			break;

		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (dist[nx][ny] != -1) continue;

			dist[nx][ny] = dist[x][y] + 1;
			q.push({nx, ny});
		}
	}
	cout << dist[p[1].first][p[1].second];
	return 0;
}