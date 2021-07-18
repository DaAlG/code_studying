#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k;
int map[21][21];
pair<int, int> scent[21][21];
int dir[401];
int prior[401][5][4];

int dx[] = { 0, -1, 1, 0, 0 };
int dy[] = { 0, 0, 0, -1, 1 };

bool check(int x, int y)
{
	return x > 0 && x <= n && y > 0 && y <= n;
}

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
	return a.second < b.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;

	vector<pair<pair<int, int>, int>> sharks;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) {
				sharks.push_back({ {i, j}, map[i][j] });
			}
		}
	}

	// 상어를 오름차순으로 정렬
	sort(sharks.begin(), sharks.end(), cmp);

	queue<pair<pair<int, int>, int>> shark;
	queue<pair<int, int>> sct;

	for (int i = 0; i < sharks.size(); i++) {
		shark.push(sharks[i]);

		// 처음 있는 위치에서 먼저 냄새를 뿌린다
		scent[sharks[i].first.first][sharks[i].first.second] = { sharks[i].second, k };
		sct.push(sharks[i].first);
	}

	// 처음에 보고 있는 방향
	for (int i = 1; i <= m; i++) cin >> dir[i];

	// 상어별 우선순위
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int l = 0; l < 4; l++) {
				cin >> prior[i][j][l];
			}
		}
	}

	int time = 0;
	
	// 1번 상어만 격자에 남을 때까지 반복
	while (shark.size() > 1) {
		time++;

		// 1000초가 넘어도 다른 상어가 격자에 남아있으면 종료
		if (time > 1000) {
			cout << -1;
			return 0;
		}

		int s = shark.size();

		// 상어 이동
		for (int i = 0; i < s; i++) {
			int x = shark.front().first.first;
			int y = shark.front().first.second;
			int num = shark.front().second;
			shark.pop();

			bool move = false;

			// 인접한 칸 중 아무 냄새가 없는 칸으로 이동
			for (int j = 0; j < 4; j++) {
				int d = prior[num][dir[num]][j];
				int nx = x + dx[d];
				int ny = y + dy[d];

				if (!check(nx, ny)) continue;

				
				if (map[nx][ny] == 0 && scent[nx][ny].first == 0) {
					dir[num] = d;
					shark.push({ {nx, ny}, num });
					move = true;
					break;
				}
			}

			// 아무 냄새가 없는 칸이 없으면 자신의 냄새가 있는 칸으로 이동
			if (move == false) {
				for (int j = 0; j < 4; j++) {
					int d = prior[num][dir[num]][j];
					int nx = x + dx[d];
					int ny = y + dy[d];

					if (!check(nx, ny)) continue;

					if (scent[nx][ny].first == num) {
						dir[num] = d;
						shark.push({ {nx, ny}, num });
						scent[nx][ny].second = k;
						break;
					}
				}
			}
		}

		s = sct.size();

		// 냄새가 뿌린 칸의 남은 시간 업데이트 
		for (int i = 0; i < s; i++) {
			int x = sct.front().first;
			int y = sct.front().second;
			sct.pop();

			scent[x][y].second--;
			if (scent[x][y].second <= 0)
				scent[x][y] = { 0, 0 };
			else
				sct.push({x, y});
		}

		s = shark.size();

		// 현재 위치 업데이트
		for (int i = 0; i < s; i++) {
			int x = shark.front().first.first;
			int y = shark.front().first.second;
			int num = shark.front().second;
			shark.pop();

			// 이전에 있던 칸은 0으로
			map[x - dx[dir[num]]][y - dy[dir[num]]] = 0;
			
			// 가장 작은 번호를 가진 상어만 격자에 남는다
			if (map[x][y] == 0 || map[x][y] > num) {
				map[x][y] = num;

				// 아무 냄새가 없는 칸으로 온 경우만 sct에 추가
				if (scent[x][y].second == 0)
					sct.push({ x, y });

				scent[x][y] = { num, k };
				shark.push({ {x, y}, num });
			}
		}
	}
	cout << time;

	return 0;
}