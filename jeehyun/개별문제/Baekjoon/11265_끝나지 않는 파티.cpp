/*
 * 그래프
 * 11265 끝나지 않는 파티
 */

#include <iostream>
#define MAX 501
using namespace std;

int d[MAX][MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> d[i][j];
		}
	}

	// 플로이드 와샬
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][k] + d[k][j] < d[i][j])
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}

	while (m--) {
		int s, e, t;
		cin >> s >> e >> t;

		if (d[s][e] <= t)
			cout << "Enjoy other party\n";
		else
			cout << "Stay here\n";
	}

	return 0;
}