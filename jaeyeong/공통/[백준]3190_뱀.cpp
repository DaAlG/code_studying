using namespace std;
#include <iostream>
#include <vector>


int main() {
	int n, k, l;
	int board[101][101] = {};
	int x, y, time = 0;
	int headX = 1, headY = 1, d = 0;
	int direction[4][2] = { 0, 1, //동
							1, 0, //남
							0, -1, //서
							-1, 0}; //북
	char c;
	bool die = false;
	int east = 0, west = 1, south = 2, north = 3;
	vector<pair<int, char>> info;
	vector<pair<int, int>> tail;

	cin >> n >> k;
	board[headX][headY] = 1; //뱀은 1
	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		board[x][y] = 2; //사과는 2
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		cin >> x >> c;
		info.push_back(make_pair(x, c));
	}
	tail.push_back(make_pair(headX, headY));

	while (die == false) {
		//시간++
		time++;

		//뱀이동불가지역이면
		if ((headX + direction[d][0]) > n || (headY + direction[d][1]) > n || 
			(headX + direction[d][0]) <= 0 || (headY + direction[d][1]) <= 0 ||
			board[headX + direction[d][0]][headY + direction[d][1]] == 1) {
			die = true;
			continue;
		}
		
		//사과 없으면
		if (board[headX + direction[d][0]][headY + direction[d][1]] != 2) {
			board[tail[0].first][tail[0].second] = 0;
			tail.erase(tail.begin());
		}
		//뱀이동
		board[headX + direction[d][0]][headY + direction[d][1]] = 1;

		headX += direction[d][0];
		headY += direction[d][1];
		tail.push_back(make_pair(headX, headY));

		//방향전환
		if (info.empty() ==false && info[0].first == time) {
			if (info[0].second == 'L') {
				d -= 1;
				if (d == -1)
					d = 3;
			}
			else {
				d += 1;
				if (d == 4)
					d = 0;
			}
			info.erase(info.begin());
		}
	}

	printf("%d\n", time);
}