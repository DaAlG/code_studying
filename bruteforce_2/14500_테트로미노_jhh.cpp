/*
폴리오미노는 크기가 1*1인 정사각형을 여러개 이어 붙여서 만든 도형
정사각형 4개를 이어 붙인 폴리오미노는 테트로미노, 총 다섯가지가 있음
n*m크기의 종이 위에 테트로미노를 하나 놓아서 놓인칸에 쓰여있는 수의 합을 최대로 하는 문제
*/
#include<iostream>
using namespace std;
int a[500][500];
bool c[500][500];
int n, m;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int ans = 0;

void go(int x, int y, int sum, int cnt) {
	//모든 테트로미노가 하나의 칸에서 3칸씩 이동하는 방식으로 만들 수 있기 때문에
	/*예외: ***
			 *      인 경우
	*/
	if (cnt == 4) {//네개값해서 최대값구하면 return
		if (ans < sum) ans = sum;
		return;
	}
	if (x < 0 || x >= n || y < 0 || y >= m) return; //범위를 벗어난 경우
	if (c[x][y]) return;
	c[x][y] = true;
	for (int k = 0; k < 4; k++)
		go(x + dx[k], y + dy[k], sum + a[x][y], cnt + 1);//인접한 네 칸
	c[x][y] = false;//방문하지 않았다는 것을 check 방문하지 않았다고 해야함 (dfs와의 차이점)
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			go(i, j, 0, 0);//모든 i,j에서 시작
			if (j + 2 < m) {
				int temp = a[i][j] + a[i][j + 1] + a[i][j + 2];
				if (i - 1 >= 0) {
					int temp2 = temp + a[i - 1][j + 1];
					if (ans < temp2)ans = temp2;
				}
				if (i + 1 < n) {
					int temp2 = temp + a[i + 1][j + 1];
					if (ans < temp2)ans = temp2;
				}
			}
			if (i + 2 < n) {
				int temp = a[i][j] + a[i + 1][j] + a[i + 2][j];
				if (j + 1 < m) {
					int temp2 = temp + a[i + 1][j + 1];
					if (ans < temp2) ans = temp2;
				}
				if (j - 1 >= 0) {
					int temp2 = temp + a[i + 1][j - 1];
					if (ans < temp2) ans = temp2;
				}

			}
		}
	}
	cout << ans << '\n';;
	return 0;
}