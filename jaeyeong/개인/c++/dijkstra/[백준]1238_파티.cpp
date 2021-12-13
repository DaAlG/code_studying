using namespace std;
#include <iostream>
#include <queue>
#include <vector>
#define MAX 1001

int n, m;
int graph[MAX][MAX];
int d[MAX][MAX];
int res[MAX];

int floyd(int start) {	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			d[i][j] = graph[i][j];
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	int answer = -1;
	for (int i = 1; i <= n; i++) {
		answer = max(d[i][start] + d[start][i], answer);
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int start;
	cin >> n >> m >> start;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) graph[i][j] = 0;
			else graph[i][j] = 0x3f3f3f3f;
		}
	}

	int x, y, z;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		graph[x][y] = z;
	}
	int answer = floyd(start);
	cout << answer << '\n';

	return 0;
}