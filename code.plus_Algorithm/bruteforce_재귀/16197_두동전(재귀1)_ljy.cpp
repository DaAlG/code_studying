/*
두 동전

N×M 크기의 보드와 4개의 버튼으로 이루어진 게임이 있다.
각각의 칸은 비어있거나 벽이다.
서로 다른 위치의 두 빈 칸에 두개의 동전이 각각 놓여져 있다.
버튼은 왼쪽, 오른쪽, 위, 아래와 같이 4가지가 있다.
버튼을 누르면 두 동전이 버튼에 쓰여 있는 방향으로 동시에 이동하게 된다.
-동전이 이동하려는 칸이 벽이면, 동전은 이동하지 않는다.
-동전이 이동하려는 방향에 칸이 없으면 동전은 보드 바깥으로 떨어진다.
-그 외의 경우에는 이동하려는 방향으로 한 칸 이동한다. 이동하련느 칸에 동전이 있는 경우에도 한 칸 이동한다.

두 동전 중 하나만 보드에서 떨어뜨리기 위해 버튼을 최소 몇 번 눌러야하는지 구하는 프로그램을 작성하시오.

(입력)
첫째 줄에 보드의 세로 크기 N과 가로 크기 M (1 ≤ N, M ≤ 20)
둘째 줄부터 N개의 줄에는 보드의 상태가 주어진다.
o: 동전
.: 빈 칸
#: 벽
동전의 개수는 항상 2개이다.
(출력)
첫째 줄에 두 동전 중 하나만 보드에서 떨어뜨리기 위해 눌러야 하는 버튼의 최소 횟수를 출력한다.
만약, 두 동전을 떨어뜨릴 수 없거나, 버튼을 10번보다 많이 눌러야 한다면, -1을 출력

(입력1)
1 2
oo
(출력1)
1
(입력2)
6 2
.#
.#
.#
o#
o#
##
(출력2)
4
*/
#include <iostream>
using namespace std;
int n, m;
string a[20];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int go(int step, int x1, int y1, int x2, int y2) {
	//11번 넘어가면 -1 반환
	if (step == 11) return -1;

	//동전1, 2 중 하나가 떨어졌니?
	bool fall1 = false, fall2 = false;
	if (x1 < 0 || x1 >= n || y1 < 0) fall1 = true;
	if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m) fall2 = true;
	if (fall1 && fall2) return -1;
	if (fall1 || fall2) return step;

	int ans = -1;
	for (int k = 0; k < 4; k++) {
		//이동
		int nx1 = x1 + dx[k];
		int ny1 = y1 + dy[k];
		int nx2 = x2 + dx[k];
		int ny2 = y2 + dy[k];
		//이동한 자리가 벽이라면
		if (0 <= nx1 && nx1 < n && 0 <= ny1 && ny1 < m && a[nx1][ny1] == '#') {
			nx1 = x1;
			ny1 = y1;
		}
		if (0 <= nx2 && nx2 < n && 0 <= ny2 && ny2 < m && a[nx2][ny2] == '#') {
			nx2 = x2;
			ny2 = y2;
		}

		int temp = go(step + 1, nx1, ny1, nx2, ny2);
		if (temp == -1) continue;
		if (ans == -1 || ans > temp) {
			ans = temp;
		}
	}
	return ans;
}
int main() {
	cin >> n >> m;
	int x1, y1, x2, y2;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'o') {
				if (x1 == -1) {
					x1 = i;
					y1 = j;
				}
				else {
					x2 = i;
					y2 = j;
				}
				a[i][j] = '.';
			}
		}
	}
	cout << go(0, x1, y1, x2, y2) << '\n';
	return;
}
