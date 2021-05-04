/*
 * 그래프
 * 1238 파티
 * Floyd Warshall Algorithm
 */

#include <iostream>
#include <algorithm>
#define MAX 1001
#define INF 0x3f3f3f
using namespace std;

int d[MAX][MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, start;
	cin >> n >> m >> start;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) d[i][j] = 0;
			else d[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		int u, v, t;
		cin >> u >> v >> t;
		d[u][v] = t;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		answer = max(answer, d[i][start] + d[start][i]);
	}
	cout << answer;

	return 0;
}