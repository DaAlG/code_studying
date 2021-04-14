/*
 * 브루트포스
 * 21278 호석이 두 마리 치킨
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 101
#define INF 0x3f3f3f
using namespace std;

int cost[MAX][MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j)
				cost[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cost[a][b] = 2;
		cost[b][a] = 2;
	}

	// 플로이드 와샬
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (cost[i][j] > cost[i][k] + cost[k][j]) {
					cost[i][j] = cost[i][k] + cost[k][j];
				}
			}
		}
	}

	int chicken[2];
	int answer = INF;

	vector<int> perm(n + 1, 0);
	perm[1] = perm[2] = 1;

	do {
		int tmp[2];
		int index = 0;
		for (int i = 1; i <= n; i++) {
			if (perm[i]) {
				tmp[index++] = i;
			}
		}

		int total = 0;
		for (int i = 1; i <= n; i++) {
			total += min(cost[i][tmp[0]], cost[i][tmp[1]]);
		}

		if (answer > total) {
			answer = total;
			chicken[0] = tmp[0];
			chicken[1] = tmp[1];
		}

	} while (prev_permutation(perm.begin() + 1, perm.end()));

	cout << chicken[0] << ' ';
	cout << chicken[1] << ' ';
	cout << answer;
	
	return 0;
}