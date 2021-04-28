#include <iostream>
using namespace std;

int n, m;
int map[5][5];
bool visited[5][5];
int answer = 0;

int rightUp(int x, int y) // ㄱ
{
	return 2 * map[x][y] + map[x + 1][y] + map[x][y - 1];
}

int rightDown(int x, int y) // _ㅣ
{
	return 2 * map[x][y] + map[x - 1][y] + map[x][y - 1];
}

int leftUp(int x, int y) // r
{
	return 2 * map[x][y] + map[x + 1][y] + map[x][y + 1];
}

int leftDown(int x, int y) // ㄴ
{
	return 2 * map[x][y] + map[x - 1][y] + map[x][y + 1];
}

void dfs(int x, int y, int sum) 
{
	if (y == m) { // 다음줄로 넘어간다
		y = 0;
		x++;
	}

	if (x == n) { // 부메랑을 다 만든 경우
		answer = max(answer, sum);
		return;
	}

	if (!visited[x][y]) {
		if (x + 1 < n && y - 1 >= 0 && !visited[x + 1][y] && !visited[x][y - 1]) {
			visited[x][y] = true;
			visited[x + 1][y] = true;
			visited[x][y - 1] = true;
			int nsum = sum + rightUp(x, y);
			dfs(x, y + 1, nsum);
			visited[x][y] = false;
			visited[x + 1][y] = false;
			visited[x][y - 1] = false;
		}

		if (x - 1 >= 0 && y - 1 >= 0 && !visited[x - 1][y] && !visited[x][y - 1]) {
			visited[x][y] = true;
			visited[x - 1][y] = true;
			visited[x][y - 1] = true;
			int nsum = sum + rightDown(x, y);
			dfs(x, y + 1, nsum);
			visited[x][y] = false;
			visited[x - 1][y] = false;
			visited[x][y - 1] = false;
		}

		if (x + 1 < n && y + 1 < m && !visited[x + 1][y] && !visited[x][y + 1]) {
			visited[x][y] = true;
			visited[x + 1][y] = true;
			visited[x][y + 1] = true;
			int nsum = sum + leftUp(x, y);
			dfs(x, y + 1, nsum);
			visited[x][y] = false;
			visited[x + 1][y] = false;
			visited[x][y + 1] = false;
		}

		if (x - 1 >= 0 && y + 1 < m && !visited[x - 1][y] && !visited[x][y + 1]) {
			visited[x][y] = true;
			visited[x - 1][y] = true;
			visited[x][y + 1] = true;
			int nsum = sum + leftDown(x, y);
			dfs(x, y + 1, nsum);
			visited[x][y] = false;
			visited[x - 1][y] = false;
			visited[x][y + 1] = false;
		}
	}

	// 부메랑을 만들지 않는다
	dfs(x, y + 1, sum);
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	dfs(0, 0, 0);
	cout << answer;
	
	return 0;
}