#include <iostream>
#include <queue>
#include <cstring>
#define MAX 101
using namespace std;

int n, m;
int dist[MAX][MAX];

bool bfs(int k) {
	queue<pair<int, int>> q;
	q.push({ 1, 1 });
	dist[1][1] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == n && y == m) {
			if (dist[x][y] == k)
				return true;
			else
				return false;
		}

		if (y + 1 <= m && dist[x][y+1] == -1) {
			dist[x][y + 1] = dist[x][y] + x;
			q.push({ x, y + 1 });
		}

		if (x + 1 <= n && dist[x + 1][y] == -1) {
			dist[x + 1][y] = dist[x][y] + y;
			q.push({ x + 1, y });
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int k;
		cin >> n >> m >> k;
		
		memset(dist, -1, sizeof(dist));

		if (bfs(k))
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}