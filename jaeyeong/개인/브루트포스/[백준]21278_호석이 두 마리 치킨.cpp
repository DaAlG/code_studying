using namespace std;
#include <iostream>
#include <cstring>
#define INF 0x3f3f3f3f

int n, m;
int input[101][101], d[101][101];
int ans = INF, d1, d2;

void getRes() {
	int res;
	//i, j에 치킨집이 있을 때 건물 k와의 거리를 구하자
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			res = 0;
			for (int k = 1; k <= n; k++) {
				res += (min(d[i][k], d[j][k])) * 2;
			}
			if (res < ans) {
				ans = res;
				d1 = i;
				d2 = j;
			}
		}
	}
}
void floyd() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			d[i][j] = input[i][j];

	//k = 거쳐가는 노드
	for (int k = 1; k <= n; k++) {
		//i 출발 노드
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][k] + d[k][j] < d[i][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	getRes();
}
int main() {
	int x, y;
	cin >> n >> m;
	memset(input, INF, sizeof(input));
	for (int i = 1; i <= n; i++)
		input[i][i] = 0;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		input[x][y] = 1;
		input[y][x] = 1;
	}
	floyd();
	cout << d1 << ' ' << d2 << ' ' << ans <<'\n';
}