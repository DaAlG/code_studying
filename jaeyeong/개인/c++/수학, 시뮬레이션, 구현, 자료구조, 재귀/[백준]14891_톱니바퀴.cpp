using namespace std;
#include <iostream>
#include <cstring>
#include <cmath>

int wheel[4][8]; //0은 N극, S극은 1
int turn[100][2]; //[0]은 번호. [1]- 1, 시계방향, -1 반시계방향
int k;
int three = 2, nine = 6;//세시방향 아홉시방향
bool visit[4];

void move(int num, int dir) {

	if (dir == -1) { // 반시계
		int temp = wheel[num][0];
		for (int i = 1; i < 8; i++)
			wheel[num][i - 1] = wheel[num][i];
		wheel[num][7] = temp;
	}
	else { // 시계
		int temp = wheel[num][7];
		for (int i = 7; 0 < i; i--) {
			wheel[num][i] = wheel[num][i - 1];
		}
		wheel[num][0] = temp;
	}
}
void solve(int num, int dir, int from) {
	int wh3 = wheel[num][three];
	int wh9 = wheel[num][nine];
	move(num, dir);
	visit[num] = true;
	if (num != 3 && wh3 != wheel[num + 1][nine] && !visit[num+1]) {
		solve(num + 1, -1 * dir, num);
	}
	if (num != 0 && wh9 != wheel[num - 1][three] && !visit[num-1]) {
		solve(num - 1, -1 * dir, num);
	}
}
int main() {
	char x;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> x;
			wheel[i][j] = x - '0';
		}
	}
	cin >> k;
	for (int i = 0; i < k; i++)
		cin >> turn[i][0] >> turn[i][1];
	for (int i = 0; i < k; i++) {
		solve(turn[i][0]-1, turn[i][1], -1);
		memset(visit, 0, sizeof(visit));
	}
	int answer = 0;
	for (int i = 0; i < 4; i++)
		if (wheel[i][0] == 1)
			answer += pow(2,i);
	cout << answer << '\n';
}