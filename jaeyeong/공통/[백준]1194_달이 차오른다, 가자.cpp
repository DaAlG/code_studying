using namespace std;
#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>

char maze[50][50];
bool visit[50][50][1<<6];
int n, m;
int direction[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

bool haveKey(int curKey, char door) {
	if ((curKey & (1 << (door - 'A'))) == 0) return false;
	return true;
}

int set_key(int curKey, char value) {
	return curKey | (1 << (value - 'a'));
}

int solution(int sx, int sy) {
	
	queue<tuple<int,int, int,int>> q;
	q.push(make_tuple(sx, sy,0, 0)); //(x, y,내가 현재 가진 키, 이동횟수)
	visit[sx][sy][0] = true;
	int answer = -1;

	while (!q.empty()) {
		int x, y, curkey, cnt;
		tie(x, y, curkey, cnt) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + direction[i][0];
			int ny = y + direction[i][1];
			if (nx < 0 || n <= nx) continue;
			if (ny < 0 || m <= ny) continue;
			if (maze[nx][ny] == '#' || visit[nx][ny][curkey]) continue;
			if ('A' <= maze[nx][ny] && maze[nx][ny] <= 'F') { //문
				if (haveKey(curkey, maze[nx][ny]) == true) {
					q.push(make_tuple(nx, ny, curkey, cnt + 1));
					visit[nx][ny][curkey] = true;
				}
			}
			else if ('a' <= maze[nx][ny] && maze[nx][ny] <= 'f') {
				int mykey = set_key(curkey, maze[nx][ny]);
				q.push(make_tuple(nx, ny, mykey, cnt + 1));
				visit[nx][ny][mykey] = true;
			}
			else if (maze[nx][ny] == '1') return answer = cnt+1;
			else {
				q.push(make_tuple(nx, ny, curkey, cnt + 1));
				visit[nx][ny][curkey] = true;
			}
		}
	}
	return answer;
}
int main() {
	char x;
	int startX, startY;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> x;
			maze[i][j] = x;
			if (x == '0') {
				startX = i;
				startY = j;
				maze[i][j] = '.';
			}
		}
	}
	cout<<solution(startX, startY)<<'\n';
}