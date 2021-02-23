using namespace std;
#include <iostream>
#include <vector>


int main() {
	int n, k, l;
	int board[101][101] = {};
	int x, y, time = 0;
	int headX = 1, headY = 1, d = 0;
	int direction[4][2] = { 0, 1, //��
							1, 0, //��
							0, -1, //��
							-1, 0}; //��
	char c;
	bool die = false;
	int east = 0, west = 1, south = 2, north = 3;
	vector<pair<int, char>> info;
	vector<pair<int, int>> tail;

	cin >> n >> k;
	board[headX][headY] = 1; //���� 1
	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		board[x][y] = 2; //����� 2
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		cin >> x >> c;
		info.push_back(make_pair(x, c));
	}
	tail.push_back(make_pair(headX, headY));

	while (die == false) {
		//�ð�++
		time++;

		//���̵��Ұ������̸�
		if ((headX + direction[d][0]) > n || (headY + direction[d][1]) > n || 
			(headX + direction[d][0]) <= 0 || (headY + direction[d][1]) <= 0 ||
			board[headX + direction[d][0]][headY + direction[d][1]] == 1) {
			die = true;
			continue;
		}
		
		//��� ������
		if (board[headX + direction[d][0]][headY + direction[d][1]] != 2) {
			board[tail[0].first][tail[0].second] = 0;
			tail.erase(tail.begin());
		}
		//���̵�
		board[headX + direction[d][0]][headY + direction[d][1]] = 1;

		headX += direction[d][0];
		headY += direction[d][1];
		tail.push_back(make_pair(headX, headY));

		//������ȯ
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