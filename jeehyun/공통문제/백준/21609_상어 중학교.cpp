#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
int map[20][20];
bool visited[20][20]; // 일반 블록 방문 여부
bool rvisited[20][20]; // 무지개 블록은 중복해서 탐색할 수 있으므로 따로 관리

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int rcnt; // 무지개블록 개수

void downwards() 
{
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] >= 0) {
				int row = i;
				while (row + 1 < n && map[row + 1][j] == -2) {
					swap(map[row][j], map[row + 1][j]);
					row++;
				}
			}
		}
	}
}

void rotate() 
{
	int nmap[20][20];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			nmap[n - j - 1][i] = map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = nmap[i][j];
		}
	}
}

void dfs(vector<pair<int, int>> &group, int x, int y, int color) 
{
	if (map[x][y] == 0) rvisited[x][y] = true;
	else visited[x][y] = true;
	group.push_back({x, y});

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n || map[nx][ny] < 0) continue;

		if (map[nx][ny] == 0 && !rvisited[nx][ny]) {
			rcnt++;
			dfs(group, nx, ny, color);
		}
		else if (map[nx][ny] == color && !visited[nx][ny]) {
			dfs(group, nx, ny, color);
		}
	}
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	vector<pair<int, int>> block;
	int rainbow = 0;
	int answer = 0;

	while (1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j] && map[i][j] > 0) {
					memset(rvisited, false, sizeof(rvisited));
					vector<pair<int, int>> tmp;
					rcnt = 0;
					dfs(tmp, i, j, map[i][j]);

					if (tmp.size() > 1) {
						// 새로 찾은 블록 그룹이 크기가 더 크면 갱신
						// 크기가 같을 때 무지개 블록 수가 큰 블록 그룹을 선택
						// 무지개 블록 수가 같으면 행, 열이 더 큰 것을 선택
						if (tmp.size() > block.size() || (tmp.size() == block.size() && rcnt >= rainbow)) {
							rainbow = rcnt;
							block = tmp;
						}
					}
				}
			}
		}

		if (block.size() < 1)
			break;

		answer += block.size() * block.size();
		
		// 블록 그룹 제거
		for (pair<int, int> p : block) {
			map[p.first][p.second] = -2; 
		}

		// 블록 그룹 정보 리셋
		block.clear();
		rainbow = 0;

		memset(visited, false, sizeof(visited));

		downwards();
		rotate();
		downwards();
	}
	cout << answer;
	return 0;
}