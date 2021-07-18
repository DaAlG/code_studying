using namespace std;
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>

typedef tuple<int, int, int> shark; // (상어번호, 위치 x, 위치 y)

int n, m, k; // N 격자의 크기, M 상어의 수, K 향기 지속 시간
vector<shark> sharks;
int scent[2][20][20]; //[0]에는 향기의 카운트, [1]에는 향기의 주인
int board[2][20][20]; //현재 상어의 번호와 방향
int nextBoard[2][20][20]; //다음 상어의 번호와 방향
int pq[401][5][5]; //[상어번호][현재방향][다음방향 우선순위들]
int dx[5] = { 0,-1,1,0,0 };
int dy[5] = { 0,0,0,-1,1 };
//위 아래 왼쪽 오른쪽 

bool inRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

void move_shark() { // nextBoard 정보만 바꾼다.
	int size = sharks.size();
	vector<int> toDelete;
	for (int i = 0; i < size; i++) {
		bool done = false;
		int num, x, y;
		tie(num, x, y) = sharks[i];
		int cur_dir = board[1][x][y];

		//향기가 없는 곳이면 이동
		for (int j = 1; j <= 4; j++) {
			int next_dir = pq[num][cur_dir][j];
			int nx = x + dx[next_dir];
			int ny = y + dy[next_dir];

			if (!inRange(nx, ny)) continue;
			if (scent[0][nx][ny] == 0) {
				done = true;
				if (nextBoard[0][nx][ny] != 0) { //이미 선점한 상어가 있다면 쫓겨남
					toDelete.push_back(i);
					break;
				}
				nextBoard[0][nx][ny] = num;
				nextBoard[1][nx][ny] = next_dir;
				sharks[i] = make_tuple(num, nx, ny);
				break;
			}
		}
		if (done == true) continue;
		//향기가 없는 곳이 없다면 자기 향기 있는 곳으로 이동
		for (int j = 1; j <= 4; j++) {
			int next_dir = pq[num][cur_dir][j];
			int nx = x + dx[next_dir];
			int ny = y + dy[next_dir];

			if (!inRange(nx, ny)) continue;
			if (scent[1][nx][ny] == num) {
				nextBoard[0][nx][ny] = num;
				nextBoard[1][nx][ny] = next_dir;
				sharks[i] = make_tuple(num, nx, ny);
				done = true;
				break;
			}
		}
		if (done == false) {
			nextBoard[0][x][y] = num;
			nextBoard[1][x][y] = cur_dir;
		}
	}
	while (!toDelete.empty()) {
		sharks.erase(sharks.begin() + toDelete.back());
		toDelete.pop_back();
	}
}

void update() {
	//향기 업데이트
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (nextBoard[0][i][j] != 0) {
				scent[0][i][j] = k;
				scent[1][i][j] = nextBoard[0][i][j];
			}
			else if(scent[0][i][j]!=0) {
				if (--scent[0][i][j] == 0)
					scent[1][i][j] = 0;
			}
		}
	}
	memcpy(board, nextBoard, sizeof(board));
	memset(nextBoard, 0, sizeof(nextBoard));
}
int solve() { //1번 상어가 홀로 남기까지 걸리는 시간
	int ans = 0;
	while (sharks.size() > 1 && ans <= 1000) {
		move_shark();
		update();
		ans++;
	}
	if (ans > 1000) return -1;
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0, w; j < n; j++) {
			cin >> board[0][i][j];
			if (board[0][i][j] != 0) {
				sharks.push_back(make_tuple(board[0][i][j], i, j));
				scent[0][i][j] = k;
				scent[1][i][j] = board[0][i][j];
			}
		}
	}

	sort(sharks.begin(), sharks.end()); // 상어가 센순으로 정렬
	//방향 저장
	for (int i = 0; i < sharks.size(); i++) {
		int num, x, y;
		tie(num, x, y) = sharks[i];
		cin >> board[1][x][y];
	}

	
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= 4; j++)
			for (int h = 1; h <= 4; h++)
				cin >> pq[i][j][h];

	cout<<solve()<<'\n';
}