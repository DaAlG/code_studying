#include <iostream>
#include <queue>
#define MAX 51
#define INF 0x3f3f3f
using namespace std;

int n, m;
char map[MAX][MAX];
bool visited[MAX][MAX][1 << 6];
bool keys[6];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

// 가지고 있는 열쇠로 문을 열 수 있는지 판단
bool haveKey(char ch, int key)
{
	int res = key & (1 << (ch - 'A'));
	
	if (res != 0) 
		return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	int stx, sty;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '0') {
				map[i][j] = '.';
				stx = i; sty = j;
			}
		}
	}

	// x, y, 이동횟수, 가지고 있는 키
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ { stx, sty }, { 0, 0 } });
	visited[stx][sty][0] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dist = q.front().second.first;
		int key = q.front().second.second;
		q.pop();

		if (map[x][y] == '1') {
			cout << dist;
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (visited[nx][ny][key]) continue;

			// '.'이나 '1'이면 그대로 진행
			if (map[nx][ny] == '.' || map[nx][ny] == '1') {
				visited[nx][ny][key] = true;
				q.push({ {nx, ny}, { dist + 1, key } });
			}
			// 이동하려는 칸이 열쇠라면 열쇠 상태 업데이트
			else if (map[nx][ny] >= 'a' && map[nx][ny] <= 'f') {
				int tmp_key = key | (1 << (map[nx][ny] - 'a'));
				visited[nx][ny][tmp_key] = true;
				q.push({ {nx, ny}, {dist + 1, tmp_key } });
			}
			// 이동하려는 칸이 문이라면 열 수 있는지 판단
			else if (map[nx][ny] >= 'A' && map[nx][ny] <= 'F' && haveKey(map[nx][ny], key)) {
				visited[nx][ny][key] = true;
				q.push({ {nx, ny}, {dist + 1, key } });
			}
		}
	}
	cout << -1;
	return 0;
}