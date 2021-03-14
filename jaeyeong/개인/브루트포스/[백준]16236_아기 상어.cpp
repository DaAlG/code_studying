using namespace std;
#include <iostream>
#include <queue>
#include <cstring>

int board[20][20];
int shark = 2, fish=0;
int n;
int min_dist, min_x, min_y;
int direction[4][2] = { {-1,0},{0,-1},{0,1},{1,0} }; //북서남동
int visit[20][20] = { 0 };
int eat = 0;


void init() {
	min_dist = 401;
	min_x = 21;
	min_y = 21;
	memset(visit, -1, sizeof(visit));
}

void bfs(int startX, int startY) {
	queue<pair<int, int>> q;
	int togoX, togoY;

	q.push(make_pair(startX, startY));
	visit[startX][startY] = 0; //방문여부가 아닌 이동거리 저장

	while (q.empty() == false) {
		pair<int, int> v = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			togoX = v.first + direction[i][0];
			togoY = v.second + direction[i][1];
			if (togoX < 0 || togoX >= n || togoY < 0 || togoY >= n) continue;
			if (visit[togoX][togoY] != -1 || shark < board[togoX][togoY]) continue;
			visit[togoX][togoY] = visit[v.first][v.second] + 1;

			if (board[togoX][togoY] < shark && board[togoX][togoY] != 0) {
				if (min_dist > visit[togoX][togoY]) {
					min_x = togoX;
					min_y = togoY;
					min_dist = visit[togoX][togoY];
				}

				else if (min_dist == visit[togoX][togoY]) {
					if (min_x == togoX) {
						if (min_y > togoY) {
							min_x = togoX;
							min_y = togoY;
						}
					}
					else if (min_x > togoX) {
						min_x = togoX;
						min_y = togoY;
					}
				}
			}
			q.push(make_pair(togoX, togoY));
		}
	}
}


int main() {
	int startX, startY, time=0;
	int answer = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				startX = i;
				startY = j;
				board[i][j] = 0;
			}
			else if (board[i][j] != 0)
				fish++;
		}
	}

	while (1) {
		init();
		//bfs 1회에 먹을 수 있는, 가장 가까운 물고기의 위치 min_x,min_y와 거리 min_dist를 구한다.
		bfs(startX, startY);
		if (min_x != 21 && min_y != 21) {
			answer += min_dist;
			eat++;
			if (eat == shark) {
				shark++;
				eat = 0;
			}
			fish--;
			startX = min_x;
			startY = min_y;
			board[startX][startY] = 0;
		}
		else
			break;
	}
	cout << answer;
}