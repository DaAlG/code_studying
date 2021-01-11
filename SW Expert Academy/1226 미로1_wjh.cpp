// SW Expert Academy
// S/W 문제해결 기본 7일차 - 1226 미로1

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

using namespace std;

int map[16][16];
bool visited[16][16] = { false, };
int dx[] = { -1, 1, 0, 0 }; // 상하좌우 세로
int dy[] = { 0, 0, -1, 1 }; // 상하좌우 가로

bool go(int x, int y)
{
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (map[nx][ny] == 1) continue;
		
		if (!visited[nx][ny] && map[nx][ny] == 0) {
			visited[nx][ny] = true;

			if (go(nx, ny))
				return true;

			visited[nx][ny] = false;
		}

		if (map[nx][ny] == 3)
			return true;
	}

	return false;
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case) {
		
		cin >> test_case;
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 16; j++) {
				scanf("%1d", &map[i][j]);
				visited[i][j] = false;
			}
		}

		visited[1][1] = true;
		int ans = go(1, 1);
		cout << "#" << test_case << " " << ans << endl;
	}

	return 0;
}