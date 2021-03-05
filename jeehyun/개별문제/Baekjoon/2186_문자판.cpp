/* 브루트포스
 * 2186 문자판
 * DFS + DP(Memoization)
 */

#include <iostream>
#include <string>
#include <cstring>
#define MAX 100
using namespace std;

int n, m, k;
string TARGET;

char board[MAX][MAX];
int dp[MAX][MAX][80];

int dx[] = { -1, 1, 0, 0 }; // 상하좌우
int dy[] = { 0, 0, -1, 1 };

int dfs(int x, int y, int idx)
{
	// 이미 탐색한 지점이므로 더 이상 탐색하지 않아도 된다
	if (dp[x][y][idx] != -1) return dp[x][y][idx];

	// 마지막 문자까지 찾았다면 더 이상의 탐색은 필요없다
	if (idx >= TARGET.size()) return 1;

	// (x, y)에 있는 알파벳을 TARGET의 idx번 인덱스로 설정했을 때, 나올 수 있는 정답의 개수
	dp[x][y][idx] = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= k; j++) {
			int nx = x + j * dx[i];
			int ny = y + j * dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] != TARGET[idx]) continue;

			dp[x][y][idx] = dp[x][y][idx] + dfs(nx, ny, idx + 1);
		}
	}
	return dp[x][y][idx];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	cin >> TARGET;

	// dp[][][] = 0이라는 것은 해당 좌표에 있는 값을 특정 인덱스로 설정했을 때
	// 나올 수 있는 경우의 수가 0이라는 의미이므로 -1로 초기값 설정
	memset(dp, -1, sizeof(dp));

	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == TARGET[0]) {
				answer += dfs(i, j, 1);
			}
		}
	}
	cout << answer;

	return 0;
}