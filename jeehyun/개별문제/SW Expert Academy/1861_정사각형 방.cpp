#include <iostream>
#include <cstring>
#define MAX 1000
using namespace std;

int n;
int map[MAX][MAX];
int moveCnt[MAX][MAX];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int dfs(int x, int y)
{
	// 이미 방문한 방이면 이동횟수 리턴
	if (moveCnt[x][y] != 0) return moveCnt[x][y];

	// 자기 자신도 이동횟수로 카운트하므로 1
	moveCnt[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		
		// 이동하려는 방에 적힌 숫자가 현재 방에 적힌 숫자보다 정확히 1 더 커야함
		if (map[nx][ny] == map[x][y] + 1) {
			moveCnt[x][y] += dfs(nx, ny);
		}
	}
	return moveCnt[x][y];
}

int main(int argc, char** argv)
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> n;

		memset(moveCnt, 0, sizeof(moveCnt));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		int answer = 0;
		int maxCnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int cnt = dfs(i, j);

				// 더 많이 이동할 수 있거나 이동횟수는 같은데 적힌 숫자가 더 작을 경우 갱신
				if (cnt > maxCnt || (cnt == maxCnt && answer > map[i][j])) {
					answer = map[i][j];
					maxCnt = cnt;
				}
			}
		}
		cout << "#" << tc << " " << answer << " " << maxCnt << "\n";
	}
	return 0;
}