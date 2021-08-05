#include <iostream>
#include <vector>
using namespace std;

int n, k;
int map[8][8];
int visited[8][8];
int answer;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void dfs(int x, int y, int len)
{
	visited[x][y] = true;

	if (answer < len) answer = len;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) continue;

		if (map[nx][ny] < map[x][y]) { // 낮은 지형으로 등산로 연결
			dfs(nx, ny, len + 1);
		}
	}

	visited[x][y] = false;
}

int main(int argc, char** argv)
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case) {
		cin >> n >> k;

		int maxHeight = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (maxHeight < map[i][j]) {
					maxHeight = map[i][j];
				}
			}
		}

		vector<pair<int, int>> peak; // 가장 높은 봉우리들
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == maxHeight)
					peak.push_back({ i, j });
			}
		}

		answer = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int cut = 1; cut <= k; cut++) {
					map[i][j] -= cut;
					for (pair<int, int> p : peak) {
						dfs(p.first, p.second, 1);
					}
					map[i][j] += cut;
				}
			}
		}

		cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;
}