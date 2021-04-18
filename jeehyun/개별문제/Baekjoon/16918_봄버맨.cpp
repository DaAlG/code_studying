/*
 * 그래프
 * 16918 봄버맨
 */

#include <iostream>
#include <vector>
#include <queue>
#define MAX 201
using namespace std;

int r, c, n;
char map[MAX][MAX];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void setBomb()
{
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			map[i][j] = 'O';
		}
	}
}

void printMap()
{
	for (int i = 0; i < r; i++) {
		cout << map[i] << '\n';
	}
}

int main()
{
	cin >> r >> c >> n;

	vector<pair<int, int>> bomb;
	for (int i = 0; i < r; i++) {
		cin >> map[i];
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 'O')
				bomb.push_back({ i, j });
		}
	}

	if (n == 1) {
		printMap();
		return 0;
	}

	queue<pair<int, int>> q({bomb.begin(), bomb.end()});
	int time = 1;

	while (time < n || !q.empty()) {
		time++;

		if (time % 2) {
			int size = q.size();
			for (int i = 0; i < size; i++) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				map[x][y] = '.';

				for (int j = 0; j < 4; j++) {
					int nx = x + dx[j];
					int ny = y + dy[j];

					if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
					if (map[nx][ny] != 'O') continue;

					map[nx][ny] = '.';
				}
			}

			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (map[i][j] == 'O')
						q.push({ i, j });
				}
			}
		}
		else
			setBomb();

		if (time == n)
			break;
	}
	
	printMap();
	return 0;
}