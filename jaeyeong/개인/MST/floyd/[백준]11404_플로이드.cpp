using namespace std;
#include <iostream>
#include <cstring>
#define INF 0x3f3f3f3f

int n, m;
int cities[101][101];

void floyd() {
	int d[101][101];
	memcpy(d, cities, sizeof(d));

	//k== 거치는 노드
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j] == INF) d[i][j] = 0;
			cout << d[i][j]<<' ';
		}
		cout << '\n';
	}
	return;
}
int main() {
	
	cin >> n >> m;
	memset(cities, INF, sizeof(cities));
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		cities[a][b] = cities[a][b] > c ? c : cities[a][b];
	}
	for (int i = 1; i <= n; i++)
		cities[i][i] = 0;

	floyd();
	return 0;
}