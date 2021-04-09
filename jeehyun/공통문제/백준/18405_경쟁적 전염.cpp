#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 201
using namespace std;

int map[MAX][MAX];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool cmp(pair<int, int>& a, pair<int, int>& b) 
{
	return map[a.first][a.second] < map[b.first][b.second];
}

int main()
{
	int n, k;
	cin >> n >> k;
	
	vector<pair<int, int>> virus;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) {
				virus.push_back({ i, j });
			}
		}
	}

	int s, x, y;
	cin >> s >> x >> y;

	if (s == 0) {
		cout << map[x][y];
		return 0;
	}

	int time = 0;
	sort(virus.begin(), virus.end(), cmp);

	while (!virus.empty()) {
		time++;

		int size = virus.size();
		for (int i = 0; i < size; i++) {
			pair<int, int> now = virus[i];

			for (int j = 0; j < 4; j++) {
				int nx = now.first + dx[j];
				int ny = now.second + dy[j];

				if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
				if (map[nx][ny] != 0) continue;

				map[nx][ny] = map[now.first][now.second];
				virus.push_back({ nx, ny });
			}
		}
		virus.erase(virus.begin(), virus.begin() + size);
		sort(virus.begin(), virus.end(), cmp);

		if (time == s) {
			cout << map[x][y];
			return 0;
		}
	}

	// s가 맵이 다 채워진 시간보다 클 때 map[x][y] 출력
	cout << map[x][y];
	return 0;
}