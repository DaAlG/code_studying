/*
 * 백트래킹
 * 15684 사다리 조작
 */

#include <iostream>
#define INF 987654321
using namespace std;

int n, m, h;
bool path[31][11];

bool possible()
{
	for (int i = 1; i <= n; i++) {
		int now = i;
		for (int pos = 1; pos <= h; pos++) {
			if (path[pos][now]) now++;
			else if (path[pos][now - 1]) now--;
		}
		if (now != i) return false;
	}
	return true;
}

int go(int now, int cnt)
{
	if (cnt > 3) return INF;
	if (possible()) return cnt;

	int ret = INF;
	for (int i = now; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (!path[i][j] && !path[i][j - 1] && !path[i][j + 1]) {
				path[i][j] = true;
				ret = min(ret, go(i, cnt + 1));
				path[i][j] = false;
			}
		}
	}
	
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		path[a][b] = true;
	}

	int answer = go(1, 0);
	if (answer == INF || answer > 3)
		cout << -1 << "\n";
	else
		cout << answer << "\n";

	return 0;
}