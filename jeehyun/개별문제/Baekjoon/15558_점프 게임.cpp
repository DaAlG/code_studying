/* 그래프
 * 15558 점프 게임
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 200001
using namespace std;

int map[MAX][2];
bool visited[MAX][2];

int main()
{
	int n, k;
	cin >> n >> k;

	fill(&map[0][0], &map[MAX - 1][2], 1);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[j][i]);
		}
	}

	int move[] = { -1, 1, k };

	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(0, 0), 0));
	visited[0][0] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int t = q.front().second;
		q.pop();

		if (x >= n) {
			cout << 1;
			return 0;
		}

		for (int i = 0; i < 3; i++) {
			int nx = x + move[i];
			int ny = y;

			if (i == 2) ny = !y;

			if (nx <= t || ny < 0 || ny >= 2) continue;
			
			if (!visited[nx][ny] && map[nx][ny]) {
				visited[nx][ny] = true;
				q.push(make_pair(make_pair(nx, ny), t + 1));
			}
		}
	}

	cout << 0;
	return 0;
}