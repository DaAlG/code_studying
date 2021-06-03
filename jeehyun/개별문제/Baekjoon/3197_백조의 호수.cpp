/*
 * 그래프
 * 3197 백조의 호수
 */

#include <iostream>
#include <queue>
#define MAX 1502
using namespace std;

int n, m;
char map[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

queue<pair<int, int>> swan;
queue<pair<int, int>> nextSwan;
queue<pair<int, int>> water;
queue<pair<int, int>> nextWater;

bool inRange(int x, int y)
{
	return x >= 0 && y >= 0 && x < n && y < m;
}

bool findSwan()
{
	while (!swan.empty()) {
		int x = swan.front().first;
		int y = swan.front().second;
		swan.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!inRange(nx, ny) || visited[nx][ny]) continue;

			// 백조가 서로 만남
			if (map[nx][ny] == 'L') {
				visited[nx][ny] = true;
				return true;
			}
			// 현재 백조가 돌아다닐 수 있는 영역
			else if (map[nx][ny] == '.') {
				visited[nx][ny] = true;
				swan.push({ nx, ny });
			}
			// 다음 날 백조가 돌아다닐 수 있게 되는 영역
			else if (map[nx][ny] == 'X') {
				visited[nx][ny] = true;
				nextSwan.push({ nx, ny });
			}
		}
	}
	return false;
}

void meltIce()
{
	while (!water.empty()) {
		int x = water.front().first;
		int y = water.front().second;
		water.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			// 다음 날 물이 될 부분
			if (inRange(nx, ny) && map[nx][ny] == 'X') {
				map[nx][ny] = '.';
				nextWater.push({ nx,ny });
			}
		}
	}
}

int main()
{
	cin >> n >> m;

	pair<int, int> pos;

	for (int i = 0; i < n; i++) {
		cin >> map[i];
		for (int j = 0; j < m; j++) {
			// 현재 물인 부분
			if (map[i][j] != 'X') {
				water.push({i, j});
			}

			// 백조 위치
			if (map[i][j] == 'L') {
				pos = { i, j };
			}
		}
	}

	int time = 0;
	swan.push(pos);
	visited[pos.first][pos.second] = true;

	while (!findSwan()) {
		// 얼음을 녹인다
		meltIce();

		water = nextWater;
		swan = nextSwan;

		// 버퍼 정리
		while (!nextWater.empty()) nextWater.pop();
		while (!nextSwan.empty()) nextSwan.pop();

		time++;
	}
	cout << time;
	return 0;
}