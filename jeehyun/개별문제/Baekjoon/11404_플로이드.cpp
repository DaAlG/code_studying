/*
 * 그래프
 * 11404 플로이드
 */

#include <iostream>
#define MAX 101
#define INF 100000000
using namespace std;

int d[MAX][MAX];

void init()
{
	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) {
			if (i == j) d[i][j] = 0;
			else d[i][j] = INF;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	init();

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		d[a][b] = min(d[a][b], c);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
 				if (d[i][k] + d[k][j] < d[i][j])
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j] == INF) d[i][j] = 0;
			cout << d[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}