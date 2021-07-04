using namespace std;
#include <iostream>
#include <vector>
#define MAX 101
/*
★한 세대의 방향정보를 역순으로 탐색하면서 +1 을 시켜준 값이
그 다음 세대의 방향정보이다.
d 방향
0: x좌표가 증가하는 방향 (→)
1: y좌표가 감소하는 방향 (↑)
2: x좌표가 감소하는 방향 (←)
3: y좌표가 증가하는 방향 (↓)
*/

int board[MAX][MAX];
int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };
int n;//드래곤 커브 수
int x, y, d, g; // (x,y) 드래곤터브 시작 점, d 시작 방향, g 세대
vector<int> dir_info;// 0 = → , 1 = ↑ , 2 = ← , 3 = ↓

void make_dragon_curve() {
	int size = dir_info.size();
	for (int i = size - 1; i >= 0; i--)
	{
		int nD = (dir_info[i] + 1) % 4;
		x += dx[nD];
		y += dy[nD];
		board[x][y] = 1;
		dir_info.push_back(nD);
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> y >> x >> d >> g;
		dir_info.clear();
		
		board[x][y] = 1;
		x += dx[d];
		y += dy[d];
		board[x][y] = 1;

		dir_info.push_back(d);
		for (int j = 0; j < g; j++)
			make_dragon_curve();
	}
	//기가 1×1인 정사각형의 네 꼭짓점이
	//모두 드래곤 커브의 일부인 것의 개수 구하기
	int cnt = 0;
	for (int i = 0; i < MAX-1; i++) {
		for (int j = 0; j < MAX-1; j++) {
			if (board[i][j] == 1 && board[i + 1][j] == 1 &&
				board[i][j + 1] == 1 && board[i + 1][j + 1] == 1)
				cnt++;
		}
	}
	cout << cnt << '\n';
}