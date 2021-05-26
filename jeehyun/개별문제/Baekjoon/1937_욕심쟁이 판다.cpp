/*
 * 그래프
 * 1937 욕심쟁이 판다
 */

#include <iostream>
#define MAX 501
using namespace std;

int n;
int map[MAX][MAX];
int dp[MAX][MAX];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int dfs(int x, int y)
{
	// 이미 방문했으면 방문하지 않는다
	if (dp[x][y] != 0) return dp[x][y];

	dp[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if (map[nx][ny] <= map[x][y]) continue;

		dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
	}

	return dp[x][y];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			answer = max(answer, dfs(i, j));
		}
	}
	cout << answer;

	return 0;
}