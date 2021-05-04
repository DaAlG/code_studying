using namespace std;
#include <iostream>

int n, m;
int Map[5][5];
bool visited[5][5];

int rightUp(int y, int x) {
	return Map[y][x - 1] + Map[y + 1][x] + 2 * Map[y][x];
}
int rightDown(int y, int x) {
	return Map[y - 1][x] + Map[y][x - 1] + 2 * Map[y][x];
}
int leftUp(int y, int x) {
	return Map[y][x + 1] + Map[y + 1][x] + 2 * Map[y][x];
}
int leftDown(int y, int x) {
	return Map[y - 1][x] + Map[y][x + 1] + 2 * Map[y][x];
}
int ans = 0;

void dfs(int y, int x, int sum) {
	if (x == m) {
		x = 0;
		y++;
	}
	if (y == n) {
		ans = max(ans, sum);
		return;
	}
    if (!visited[y][x]) {
        if (y + 1 < n && x - 1 >= 0 && !visited[y + 1][x] && !visited[y][x - 1]) {
            visited[y][x] = true;
            visited[y][x - 1] = true;
            visited[y + 1][x] = true;
            int nsum = sum + rightUp(y, x);
            dfs(y, x + 1, nsum);
            visited[y][x] = false;
            visited[y][x - 1] = false;
            visited[y + 1][x] = false;
        }
        if (y - 1 >= 0 && x - 1 >= 0 && !visited[y - 1][x] && !visited[y][x - 1]) {
            visited[y][x] = true;
            visited[y - 1][x] = true;
            visited[y][x - 1] = true;
            int nsum = sum + rightDown(y, x);
            dfs(y, x + 1, nsum);
            visited[y][x] = false;
            visited[y - 1][x] = false;
            visited[y][x - 1] = false;
        }
        if (y + 1 < n && x + 1 < m && !visited[y + 1][x] && !visited[y][x + 1]) {
            visited[y][x] = true;
            visited[y][x + 1] = true;
            visited[y + 1][x] = true;
            int nsum = sum + leftUp(y, x);
            dfs(y, x + 1, nsum);
            visited[y][x] = false;
            visited[y][x + 1] = false;
            visited[y + 1][x] = false;
        }
        if (y - 1 >= 0 && x + 1 < m && !visited[y - 1][x] && !visited[y][x + 1]) {
            visited[y][x] = true;
            visited[y - 1][x] = true;
            visited[y][x + 1] = true;
            int nsum = sum + leftDown(y, x);
            dfs(y, x + 1, nsum);
            visited[y][x] = false;
            visited[y - 1][x] = false;
            visited[y][x + 1] = false;
        }
    }
    dfs(y, x + 1, sum);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> Map[i][j];
		}
	}
	dfs(0,0,0);
	cout << ans;
	return 0;
}