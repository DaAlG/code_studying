using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f

int n, m;
int maze[101][101];
int d[101][101];
int direction[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

void dijkstra() {
	priority_queue < pair<int, pair<int, int>> > pq;
	d[1][1] = 0;
	pq.push( make_pair(0,make_pair(1,1)) );
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cx = pq.top().second.first;
		int cy = pq.top().second.second;
		pq.pop();
		if (d[cx][cy] < cost) continue;
		for (int i = 0; i < 4; i++) {
			int nx = cx + direction[i][0];
			int ny = cy + direction[i][1];
			int ncost = cost + maze[nx][ny];
			if (0 < nx && nx <= n && 0 < ny && ny <= m) {
				if (ncost < d[nx][ny]) {
					d[nx][ny] = ncost;
					pq.push(make_pair(-ncost, make_pair(nx, ny)));
				}
			}
		}
	}

}
int main() {
	char x;
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> x;
			maze[i][j] = x - '0';
			d[i][j] = INF;
		}
	}
	dijkstra();
	cout << d[n][m] << '\n';
}