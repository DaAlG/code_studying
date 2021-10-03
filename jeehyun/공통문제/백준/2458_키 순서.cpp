#include <iostream>
#include <algorithm>
#define MAX 501
#define INF 987654321
using namespace std;

int map[MAX][MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		fill_n(map[i], MAX, INF);
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][k] + map[k][j] < map[i][j]) {
					map[i][j] = map[i][k] + map[k][j];
				}
			}
		}

	}

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (map[i][j] != INF || map[j][i] != INF) {
				cnt++;
			}
		}
		if (cnt == n - 1) answer++;
	}
	cout << answer;
	return 0;
}