using namespace std;
#include <iostream>
#include <queue>
#include <tuple>

int r, c;
char board[50][50];
pair<int,int> start;
bool visit[50][50];
int direction[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

bool inRange(int x, int y) {
	return 0 <= x && x < r && 0 <= y && y < c;
}
void move_water() {
	// '*'은 이미 물이 범람한 자리
	// '@' 곧 물이 범람할 자리
	for (int i = 0; i < r; i++) {
		for (int j = 0; j< c; j++) {
			if (board[i][j] != '*') continue;
			for (int k = 0; k < 4; k++) {
				int nx = i + direction[k][0];
				int ny = j + direction[k][1];
				if (!inRange(nx, ny)) continue;
				if (board[nx][ny] == '.' || board[nx][ny] == 'S')
					board[nx][ny] = '@';
			}
		}
	}
}
int solution() {
	bool flag = false;
	int answer = -1;
	queue<tuple<int, int, int>> q; // x,y,cnt
	q.push(make_tuple(start.first,start.second,0));
	visit[start.first][start.second] = true;
	while (!q.empty()) {
		bool waterFlag = false;
		int x, y, curTime;
		tie(x, y, curTime) = q.front();
		if (curTime > answer) waterFlag = true;
		answer = curTime;
		q.pop();
		if (board[x][y] == 'D') {
			flag = true;
			break;
		}
		//물의 이동
		if(waterFlag) move_water();
		//고슴도치 이동
		for (int i = 0; i < 4; i++) {
			int nx = x + direction[i][0];
			int ny = y + direction[i][1];
			if (inRange(nx, ny) && (board[nx][ny] == '.' || board[nx][ny] == 'D') && !visit[nx][ny]) {
				visit[nx][ny] = true;
				q.push(make_tuple(nx, ny, answer+1));
			}
		}
		//@체크한 곳을 *로 바꿔주기
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (board[i][j] == '@') board[i][j] = '*';
			}
		}
	}
	return flag == true ? answer : -1;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'S') {
				start = make_pair(i, j);
				board[i][j] = '.';
			}
		}
	}
	int answer = solution();
	if (answer == -1) cout << "KAKTUS\n";
	else cout << answer << '\n';
}