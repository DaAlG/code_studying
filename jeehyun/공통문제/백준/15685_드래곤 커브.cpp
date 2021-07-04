#include <iostream>
#include <vector>
#define MAX 101
using namespace std;

bool map[MAX][MAX];

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };

void makeCurve(int x, int y, int d, int g)
{
	vector<int> dir;
	dir.push_back(d);

	for (int i = 0; i < g; i++) {
		for (int j = dir.size() - 1; j >= 0; j--) {
			int nd = (dir[j] + 1) % 4;
			x += dx[nd];
			y += dy[nd];
			map[x][y] = true;
			dir.push_back(nd);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y, d, g;
		cin >> y >> x >> d >> g;

		// 0세대 일 때 선분 하나를 그어준다
		map[x][y] = true;
		x = x + dx[d];
		y = y + dy[d];
		map[x][y] = true;

		// 다음 세대 드래곤 커브를 그린다
		makeCurve(x, y, d, g);
	}

	// 네 꼭짓점 모두 드래곤 커브의 일부인 것의 개수
	int answer = 0;

	for (int i = 0; i < MAX - 1; i++) {
		for (int j = 0; j < MAX - 1; j++) {
			if (map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1])
				answer++;
		}
	}

	cout << answer;
	return 0;
}