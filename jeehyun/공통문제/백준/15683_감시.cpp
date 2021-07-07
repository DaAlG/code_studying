#include <iostream>
#include <vector>
using namespace std;

int n, m;
int map[8][8];
vector<pair<int, int>> cctv;
int answer = 64;

int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

bool check(int x, int y)
{
	return x >= 0 && x < n&& y >= 0 && y < m;
}

void dfs(int idx)
{
	if (idx >= cctv.size()) { // 모든 카메라를 확인했으면
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 0) // 사각지대 찾기
					cnt++;
			}
		}
		answer = min(answer, cnt);
		return;
	}

	int x = cctv[idx].first;
	int y = cctv[idx].second;

	if (map[x][y] == 1) { // 한 방향만 감시
		for (int i = 0; i < 4; i++) {
			int nx = x;
			int ny = y;

			vector<pair<int, int>> area;
			while (check(nx + dx[i], ny + dy[i]) && map[nx + dx[i]][ny + dy[i]] != 6) {
				nx += dx[i];
				ny += dy[i];

				// 현재 카메라가 감시하는 영역 저장
				if (map[nx][ny] == 0) {
					map[nx][ny] = -1;
					area.push_back({ nx, ny });
				}
			}
			
			// 다음 카메라 확인
			dfs(idx + 1);

			// 원래대로 돌려준다
			for (int j = 0; j < area.size(); j++) {
				map[area[j].first][area[j].second] = 0;
			}
		}
	}
	else if (map[x][y] == 2) {
		// 왼쪽, 오른쪽 or 위, 아래
		for (int i = 0; i < 2; i++) {
			vector<pair<int, int>> area;
			for (int j = i; j < 4; j += 2) {
				int nx = x;
				int ny = y;

				while (check(nx + dx[j], ny + dy[j]) && map[nx + dx[j]][ny + dy[j]] != 6) {
					nx += dx[j];
					ny += dy[j];

					// 현재 카메라가 감시하는 영역 저장
					if (map[nx][ny] == 0) {
						map[nx][ny] = -1;
						area.push_back({ nx, ny });
					}
				}
			}

			// 다음 카메라 확인
			dfs(idx + 1);

			// 원래대로 돌려준다
			for (int j = 0; j < area.size(); j++) {
				map[area[j].first][area[j].second] = 0;
			}
		}
	}
	else if (map[x][y] == 3 || map[x][y] == 4) {
		for (int i = 0; i < 4; i++) {
			vector<pair<int, int>> area;
			for (int j = 0; j < map[x][y] - 1; j++) {
				int nd = (i + j) % 4;
				int nx = x;
				int ny = y;

				while (check(nx + dx[nd], ny + dy[nd]) && map[nx + dx[nd]][ny + dy[nd]] != 6) {
					nx += dx[nd];
					ny += dy[nd];
					
					if (map[nx][ny] == 0) {
						map[nx][ny] = -1;
						area.push_back({ nx, ny });
					}
				}
			}

			dfs(idx + 1);

			for (int j = 0; j < area.size(); j++) {
				map[area[j].first][area[j].second] = 0;
			}
		}
	}
	else if (map[x][y] == 5) { // 항상 모든 방향 감시
		for (int i = 0; i < 4; i++) {
			int nx = x;
			int ny = y;

			while (check(nx + dx[i], ny + dy[i]) && map[nx + dx[i]][ny + dy[i]] != 6) {
				nx += dx[i];
				ny += dy[i];
				
				if (map[nx][ny] == 0)
					map[nx][ny] = -1;
			}
		}
		dfs(idx + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] > 0 && map[i][j] < 6)
				cctv.push_back({i, j});
		}
	}

	dfs(0);
	cout << answer;

	return 0;
}