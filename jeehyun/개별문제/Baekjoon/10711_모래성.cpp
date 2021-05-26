/*
 * 그래프
 * 10711 모래성
 */

#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;

int h, w;
char map[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };


// 모래성이 쌓여있지 않은 부분의 개수
int adjacentSea(int x, int y)
{
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		// 현재 모래성이 있는 자리
		if (visited[nx][ny]) continue;

		if (map[nx][ny] == '.')
			cnt++;
	}

	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		cin >> map[i];
	}

	queue<pair<int, int>> q;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (map[i][j] == '.' || map[i][j] == '9') continue;
			
			// 모래성이 무너진다면 큐에 넣어준다
			if (adjacentSea(i, j) >= (map[i][j] - '0')) {
				visited[i][j] = true;
				map[i][j] = '.';
				q.push({i, j});
			}
		}
	}

	int answer = 0;

	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			// 이전에 무너진 모래성을 없앤다
			visited[x][y] = false;

			for (int j = 0; j < 8; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];

				// 이미 체크한 모래성
				if (visited[nx][ny]) continue;

				// 모래성이 아님
				if (map[nx][ny] == '.') continue;

				// 자기 모래성의 튼튼함보다 많거나 같은 경우 파도에 의해서 무너진다
				if (adjacentSea(nx, ny) >= (map[nx][ny] - '0')) {
					q.push({ nx, ny });
					map[nx][ny] = '.';
					visited[nx][ny] = true;
				}
			}
		}
		answer++;
	}
	cout << answer;

	return 0;
}