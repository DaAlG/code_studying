using namespace std;
#include <iostream>
#define MAX 801
int n, e;
int graph[MAX][MAX];
int d[MAX][MAX];

int floyd(int a1, int a2) {
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
	int answer;
	if (d[1][a1] == 0x3f3f3f3f || d[a1][a2] == 0x3f3f3f3f || d[a2][n] == 0x3f3f3f3f)
		answer = -1;
	else
		answer = min(d[1][a1] + d[a1][a2] + d[a2][n], d[1][a2] + d[a2][a1] + d[a1][n]);

	return answer;
}
int main() {
	cin >> n >> e;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)graph[i][j] = 0;
			else graph[i][j] = 0x3f3f3f3f;
		}
	}
	int x, y, z;
	for (int i = 0; i < e; i++) {
		cin >> x >> y >> z;
		graph[x][y] = z;
		graph[y][x] = z;
	}

	cin >> x >> y;
	int answer = floyd(x, y);
	cout << answer << '\n';
}