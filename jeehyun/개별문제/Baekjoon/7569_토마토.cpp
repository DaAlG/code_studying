/*
 * 그래프
 * 7569 토마토
 */

#include <iostream>
#include <vector>
#include <queue>
#define MAX 101
using namespace std;

int h, n, m;
int box[MAX][MAX][MAX];

// 위, 아래, 왼쪽, 오른쪽, 앞, 뒤
int dz[] = { -1, 1, 0, 0, 0, 0 };
int dx[] = { 0, 0, 0, 0, -1, 1 };
int dy[] = { 0, 0, -1, 1, 0, 0 };

class Tomato {
public:
	int z;
	int x;
	int y;
	Tomato(int z, int x, int y) {
		this->z = z;
		this->x = x;
		this->y = y;
	}
};

int bfs(vector<Tomato> tomatoes)
{
	if (tomatoes.empty())
		return 0;

	queue<Tomato> q({ tomatoes.begin(), tomatoes.end() });
	int days = 0;

	while (!q.empty()) {
		days++;

		int size = q.size();
		for (int i = 0; i < size; i++) {
			int z = q.front().z;
			int x = q.front().x;
			int y = q.front().y;
			q.pop();

			for (int j = 0; j < 6; j++) {
				int nz = z + dz[j];
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (nz < 0 || nx < 0 || ny < 0 || nz >= h || nx >= n || ny >= m) continue;
				if (box[nz][nx][ny] > 0 || box[nz][nx][ny] == -1) continue;

				box[nz][nx][ny] = 1;
				q.push(Tomato(nz, nx, ny));
			}
		}
	}

	return days - 1;
}

int main()
{
	cin >> m >> n >> h;

	vector<Tomato> tomatoes;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> box[i][j][k];

				if (box[i][j][k] == 1) {
					tomatoes.push_back(Tomato(i, j, k));
				}
			}
		}
	}

	int answer = bfs(tomatoes);

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (box[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
			}
		}
	}
	
	cout << answer;
	return 0;
}