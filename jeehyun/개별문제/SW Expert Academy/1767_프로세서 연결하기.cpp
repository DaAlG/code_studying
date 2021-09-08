#include <iostream>
#include <vector>
#define INF 0x7fffffff
using namespace std;

int n;
int map[12][12];
vector<pair<int, int>> core;
int answer;
int mcnt;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool isNotWall(int x, int y)
{
	return x >= 0 && x < n&& y >= 0 && y < n;
}

int possible(int x, int y, int d)
{
	int len = 0;
	x += dx[d];
	y += dy[d];
	while (isNotWall(x, y)) {
		if (map[x][y] != 0) 
			return 0;
		x += dx[d];
		y += dy[d];
		len++;
	}
	return len;
}

void connect(int x, int y, int d, int flag)
{
	x += dx[d];
	y += dy[d];
	while (isNotWall(x, y)) {
		if (flag) map[x][y] = 2;
		else map[x][y] = 0;
		x += dx[d];
		y += dy[d];
	}
}

void go(int now, int cnt, int sum)
{
	if (now >= core.size()) {
		if (cnt > mcnt) {
			mcnt = cnt;
			answer = sum;
		}
		else if (cnt == mcnt) answer = min(answer, sum);
		return;
	}

	// 전원 연결
	int x = core[now].first;
	int y = core[now].second;

	// 가장자리에 위치한 core는 이미 전원이 연결되어 있음
	if (x == 0 || x == n - 1 || y == 0 || y == n - 1) {
		go(now + 1, cnt + 1, sum);
	}
	else {
		bool check = false;
		for (int i = 0; i < 4; i++) {
			int len = possible(x, y, i);
			if (len != 0) {
				check = true;
				connect(x, y, i, 1); // 전선 연결
				go(now + 1, cnt + 1, sum + len);
				connect(x, y, i, 0); // 원래 상태로
			}
		}
		// 전원 연결이 불가능하면 넘어가기
		if (!check) go(now + 1, cnt, sum);
	}
}

int main()
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j]) core.push_back({ i, j });
			}
		}

		answer = INF;
		mcnt = 0;
		go(0, 0, 0);

		cout << "#" << test_case << " " << answer << "\n";
		core.clear();
	}
	return 0;
}