/*
 * 그래프
 * 7562 나이트의 이동
 */

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 300
using namespace std;

int dist[MAX][MAX];

int dx[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[] = { -1, 1, -2, 2, -2, 2, -1, 1 };

int main()
{
	int T, n;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> n;
		
		pair<int, int> start;
		cin >> start.first >> start.second;

		pair<int, int> dest;
		cin >> dest.first >> dest.second;


		if (start.first == dest.first && start.second == dest.second) {
			cout << 0 << '\n';
			continue;
		}

		memset(dist, -1, sizeof(dist));
		
		queue<pair<int, int>> q;
		q.push(start);
		dist[start.first][start.second] = 0;

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (x == dest.first && y == dest.second)
				break;

			for (int i = 0; i < 8; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if (dist[nx][ny] != -1) continue;

				dist[nx][ny] = dist[x][y] + 1;
				q.push({ nx, ny });
			}
		}

		while (!q.empty()) {
			q.pop();
		}

		cout << dist[dest.first][dest.second] << '\n';
	}
	
	return 0;
}