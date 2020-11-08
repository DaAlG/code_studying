/*
<테트로미노>
폴리오미노란 크기가 1x1인 정사각형을 여러 개 이어서 붙인 도형.
다음과 조건을 만족해야 한다.
-정사각형은 서로 겹치면 안 된다.
-도형은 모두 연결되어 있어야 한다.
-정사각형의 변끼리 연결되어 있어야 한다. 즉, 꼭짓점과 꼭짓점만 맞닿아 있으면 안 된다.
이 조건을 만족하여 정사각형을 4개 이어 붙인 폴리오미노를 테트로미노라고 하며 5가지 종류가 있다.

크기가 NxM인 종이 위에 테트로미노를 "하나를" 적절히 놓아서 테트로미노가 놓인 칸에 쓰여 있는 수들의 합을 최대로 하는 프로그램을 작성하시오.
테트로미노는 반드시 한 정사각형이 하나의 칸을 차지하고, 회전이나 대칭을 시켜도 된다.

(입력)
첫째 줄에 종이의 세로 크기 N과 가로 크기 M이 주어진다.(4 ≤ N, M ≤ 500)
둘째 줄부터 N개의 줄에 종이에 쓰여 있는 수가 주어진다. 입력으로 주어지는 수는 1,000을 넘지 않는 자연수이다.

(예제 입력 1)
5 5
1 2 3 4 5
5 4 3 2 1
2 3 4 5 6
6 5 4 3 2
1 2 1 2 1

(예제 출력 1)
19

(예제 입력 2)
4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5

(예제 출력 2)
20
*/

#include <iostream>
using namespace std;
int a[500][500];
bool c[500][500];
int n, m;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int ans = 0;

void go(int x, int y, int sum int cnt) {
	if (cnt == 4) {
		if (ans < sum) ans = sum;
		return;
	}
	if (x < 0 || x >= n || y < 0 || y >= m) return;
	if (c[x][y]) return;
	c[x][y] = true;
	for (int k = 0; k < 4; k++) {
		go(x + dx[k], y + dy[k], sum + a[x][y], cnt + 1);
	}
	c[x][y] = false;
}
int main() {
	/* setting */
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			go(i, j, 0, 0); //5가지 종류 중 4가지는 그냥 연속적으로 사방으로 3번 이동하면 회전, 뒤집은 꼴이다.
			//5가지중 4방으로 연속 3번 이동해서 나오는 모양이 안나오는것은 ㅓ모양인데 얘는 그냥 포문으로 대체!
			if (j + 2 < m) {
				int temp = a[i][j] + a[i][j + 1] + a[i][j + 2]; //-모양
				if (i - 1 >= 0) {
					//ㅗ모양
					int temp2 = temp + a[i - 1][j + 1];
					if (ans < temp2) ans = temp2;
				}
				if (i + 1 < n) {
					//ㅜ모양
					int temp2 = temp + a[i + 1][j + 1];
					if (ans < temp2) ans = temp2;
				}
			}
			if (i + 2 < n) {
				int temp = a[i][j] + a[i + 1][j] + a[i + 2][j]; //ㅣ모양
				if (j + 1 < m) {
					//ㅏ모양
					int temp2 = temp + a[i + 1][j + 1];
					if (ans < temp2) ans = temp2;
				}
				if (j - 1 >= 0) {
					//ㅓ모양
					int temp2 = temp + a[i + 1][j - 1];
					if (ans < temp2) ans = temp2;
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}