/*
 * 그래프
 * 2665 미로만들기
 */

#include <iostream>
#include <deque>
#define MAX 51
using namespace std;

int n;
char map[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool check(int x, int y)
{
	return x >= 0 && x < n&& y >= 0 && y < n;
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

	deque<pair<pair<int, int>, int>> q;
	q.push_back({ {0, 0}, 0 });
	visited[0][0] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop_front();

		if (x == n - 1 && y == n - 1) {
			cout << cnt;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!check(nx, ny) || visited[nx][ny]) continue;

			visited[nx][ny] = true;
			if (map[nx][ny] == '1')
				q.push_front({ {nx, ny}, cnt });
			else
				q.push_back({ {nx ,ny}, cnt + 1 });
		}
	}
	return 0;
}