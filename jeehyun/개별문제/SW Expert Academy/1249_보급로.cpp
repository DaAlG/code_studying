#include <iostream>
#include <queue>
#include <cstring>
#define MAX 100
using namespace std;

int n;
int map[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

struct Path {
	int x, y, time;
	Path(int x, int y, int time) {
		this->x = x;
		this->y = y;
		this->time = time;
	}
};

struct cmp {
	bool operator()(Path a, Path b) {
		return a.time > b.time;
	}
};

bool isNotWall(int x, int y) 
{
	return x >= 0 && x < n&& y >= 0 && y < n;
}

int bfs()
{
	memset(visited, false, sizeof(visited));
	priority_queue<Path, vector<Path>, cmp> q;
	q.push(Path(0, 0, 0));
	visited[0][0] = true;

	while (!q.empty()) {
		int x = q.top().x;
		int y = q.top().y;
		int time = q.top().time;
		q.pop();

		if (x == n - 1 && y == n - 1) {
			return time;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!isNotWall(nx, ny) || visited[nx][ny]) continue;

			visited[nx][ny] = true;
			q.push(Path(nx, ny, time + map[nx][ny]));
		}
	}

	return -1;
}

int main()
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> n;

		string tmp;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			for (int j = 0; j < n; j++) {
				map[i][j] = tmp[j] - '0';
			}
		}
		cout << "#" << test_case << " " << bfs() << "\n";
	}
	return 0;
}