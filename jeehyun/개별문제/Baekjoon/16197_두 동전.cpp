/*
 * 백트래킹
 * 16197 두 동전
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 22
#define INF 0x3f3f3f
using namespace std;

int n, m;
char map[MAX][MAX];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

struct Coin {
	int x;
	int y;
};

int go(Coin a, Coin b, int cnt)
{
	if (cnt > 10) return INF;

	int ret = INF;

	for (int i = 0; i < 4; i++) {
		Coin na = { a.x + dx[i], a.y + dy[i] };
		Coin nb = { b.x + dx[i], b.y + dy[i] };
		bool f1 = false;
		bool f2 = false;

		// 동전이 보드 위에 있는지 확인
		if (a.x < 0 || a.y < 0 || a.x >= n || a.y >= m) f1 = true;
		if (b.x < 0 || b.y < 0 || b.x >= n || b.y >= m) f2 = true;

		// 두 동전이 모두 보드 바깥으로 떨어졌다면 continue
		if (f1 && f2) continue;

		// 하나만 떨어졌으므로 성공
		if (f1 || f2) {
			ret = min(ret, cnt);
			return ret;
		}

		// 벽이면 좌표 원위치
		if (map[na.x][na.y] == '#') {
			na = a;
		}

		// 벽이면 좌표 원위치
		if (map[nb.x][nb.y] == '#') {
			nb = b;
		}

		// 두 동전이 겹쳐져 있다면 continue
		if (na.x == nb.x && na.y == nb.y) continue;

		ret = min(ret, go(na, nb, cnt + 1));
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	vector<Coin> coins;

	for (int i = 0; i < n; i++) {
		cin >> map[i];
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'o') {
				coins.push_back({ i, j });
			}
		}
	}

	int answer = go(coins[0], coins[1], 0);
	
	if (answer == INF)
		cout << -1;
	else
		cout << answer;

	return 0;
}