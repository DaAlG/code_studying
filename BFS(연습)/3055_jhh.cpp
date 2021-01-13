#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
#include<tuple>

using namespace std;
int water[50][50];
int d[50][50];
int dx[] = { 0,0,1, -1 };
int dy[] = { 1,-1,0,0 };
int main() {
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	memset(water, -1, sizeof(water));
	queue<pair<int, int>> q;
	int sx, sy, ex, ey;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '*') {
				q.push(make_pair(i, j));
				water[i][j] = 0;
			}
			else if (a[i][j] == 'S') {
				sx = i;
				sy = j;
			}
			else if (a[i][j] == 'D') {
				ex = i;
				ey = j;
			}
		}
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (water[nx][ny] != -1) continue;
			if (a[nx][ny] == 'X') continue;
			if (a[nx][ny] == 'D')continue;
			water[nx][ny] = water[x][y] + 1;
			q.push(make_pair(nx, ny));
		}
	}
	if (d[ex][ey] == -1)
		cout << "KACTUS\n";
	else
		cout << d[ex][ey] << '\n';
	return 0;

}