using namespace std;
#include <iostream>
#include <vector>
#include <cstring>
#define MAX 8
#define watch 100

int n, m;
int answer = 0x3f3f3f3f;
int room[MAX][MAX], croom[MAX][MAX];
vector<pair<int, int>> cctv;
vector<int> angle; //카메라 각도
bool visit[MAX][MAX][4]; // [x][y][0~3] 방향으로 비출 것인지
//0: 0도, 1: 270도, 2: 180도, 3:90도
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };

bool inRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

int getBlindSpot(){
	int result = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (croom[i][j] == 0)
				result++;
	return result;
}

void solve(int idx) {
	if (idx == cctv.size()) {
		for (int i = 0; i < angle.size(); i++) {
			int x = cctv[i].first;
			int y = cctv[i].second;
			for (int j = 0; j < 4; j++) {
				if (visit[x][y][j]) { //j는 x,y의 위치에 있는 i번째 카메라에게 허용된 원래 각도.
					//i번째 카메라가 angle[i]만큼 돌도록 했다.
					int nx = x + dx[(angle[i] + j) % 4];
					int ny = y + dy[(angle[i] + j) % 4];
					while (1) {
						//벽
						if (croom[nx][ny] == 6) break;
						//범위 초과
						if (!inRange(nx, ny)) break;
						//더 이상 사각지대가 아님
						if (croom[nx][ny] == 0) croom[nx][ny] = -1;
						nx += dx[(angle[i] + j) % 4];
						ny += dy[(angle[i] + j) % 4];
					}
				}
			}
		}
		answer = min(answer, getBlindSpot());
		memcpy(croom, room, sizeof(croom));
		return;
	}
	for (int i = 0; i < 4; i++) {
		angle.push_back(i);
		solve(idx + 1);
		angle.pop_back();
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> room[i][j];
			if (0 != room[i][j] && 6 != room[i][j])
				cctv.push_back(make_pair(i, j));
			switch (room[i][j]) {
			case 1:
				visit[i][j][0] = true;
				break;
			case 2:
				visit[i][j][0] = true;
				visit[i][j][2] = true;
				break;
			case 3:
				visit[i][j][0] = true;
				visit[i][j][1] = true;
				break;
			case 4:
				visit[i][j][0] = true;
				visit[i][j][1] = true;
				visit[i][j][2] = true;
				break;
			case 5:
				visit[i][j][0] = true;
				visit[i][j][1] = true;
				visit[i][j][2] = true;
				visit[i][j][3] = true;
				break;
			}
		}
	}
	memcpy(croom, room, sizeof(croom));
	solve(0);
	cout << answer << '\n';
	return 0;
}