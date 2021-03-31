using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <set>

set<tuple<int, int, int, int>> visit;
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int fromHorizontal[4][4] = { {-1,1,0,0}, {1,1,0,0}, {0,0,-1,-1}, {0,0,1,-1} };
int fromVertical[4][4] = { {1,1,0,0},{1,-1,0,0},{0,0,-1,1},{0,0,-1,-1} };
int caution[2][4][4] = {
	{{-1,0,-1,0},{1,0,1,0},{-1,0,-1,0},{1,0,1,0}},
	{{0,1,0,1},{0,-1,0,-1},{0,1,0,1},{0,-1,0,-1}}
};

bool check(vector<vector<int>> board, int direction, int i, int nx[], int ny[]) {
	int next[4]; // nextX1, nextY1, nextX2, nextY2
	int n = board.size();

	next[0] = nx[0] + caution[direction][i][0];
	next[1] = ny[0] + caution[direction][i][1];
	next[2] = nx[1] + caution[direction][i][2];
	next[3] = ny[1] + caution[direction][i][3];

	for (int i = 0; i < 4; i++)
		if (next[i] < 0 || next[i] >= n) return false;

	if (board[next[0]][next[1]] != 0) return false;
	if (board[next[2]][next[3]] != 0) return false;

	return true;
}

tuple<int, int, int, int> setTuple(int x1, int y1, int x2, int y2) {
	//horizontal일때
	if (x1 == x2) {
		if (y2 < y1)
			return make_tuple(x2, y2, x1, y1);
		else
			return make_tuple(x1, y1, x2, y2);
	}
	//vertical일때
	if (y1 == y2) {
		if (x2 < x1)
			return make_tuple(x2, y2, x1, y1);
		else
			return make_tuple(x1, y1, x2, y2);
	}
}

int solution(vector<vector<int>> board) {
	int x1, y1, x2, y2, dis;
	int cx[2], cy[2];
	int nx[2], ny[2];
	int n = board.size();
	queue<pair<int, tuple<int, int, int, int>>> q;
	q.push(make_pair(0, make_tuple(0, 0, 0, 1)));
	visit.insert(make_tuple(0, 0, 0, 1));
	while (q.empty() == false) {

		dis = q.front().first;
		tie(x1, y1, x2, y2) = q.front().second;

		q.pop();
		if (x1 == n - 1 && y1 == n - 1)
			break;
		if (x2 == n - 1 && y2 == n - 1)
			break;

		cx[0] = x1;
		cx[1] = x2;
		cy[0] = y1;
		cy[1] = y2;

		for (int i = 0; i < 4; i++) {
			nx[0] = x1 + dir[i][0];
			nx[1] = x2 + dir[i][0];
			ny[0] = y1 + dir[i][1];
			ny[1] = y2 + dir[i][1];
			if (0 <= nx[0] && nx[0] < n && 0 <= nx[1] && nx[1] < n
				&& 0 <= ny[0] && ny[0] < n && 0 <= ny[1] && ny[1] < n) {
				if (board[nx[0]][ny[0]] == 1 || board[nx[1]][ny[1]] == 1) continue;
				tuple<int, int, int, int> t = make_tuple(nx[0], ny[0], nx[1], ny[1]);
				if (visit.find(t) == visit.end()) {
					q.push(make_pair(dis + 1, t));
					visit.insert(t);
				}
			}
		}

		if (x1 == x2) {
			for (int i = 0; i < 4; i++) {
				nx[0] = x1 + fromHorizontal[i][0];
				ny[0] = y1 + fromHorizontal[i][1];
				nx[1] = x2 + fromHorizontal[i][2];
				ny[1] = y2 + fromHorizontal[i][3];
				if (0 <= nx[0] && nx[0] < n && 0 <= nx[1] && nx[1] < n
					&& 0 <= ny[0] && ny[0] < n && 0 <= ny[1] && ny[1] < n) {
					if (check(board, 0, i, cx, cy) == false) continue;
					if (board[nx[0]][ny[0]] == 1 || board[nx[1]][ny[1]] == 1) continue;
					tuple<int, int, int, int> t = setTuple(nx[0], ny[0], nx[1], ny[1]);
					if (visit.find(t) == visit.end()) {
						q.push(make_pair(dis + 1, t));
						visit.insert(t);
					}
				}
			}
		}
		if (y1 == y2) {
			for (int i = 0; i < 4; i++) {
				nx[0] = x1 + fromVertical[i][0];
				ny[0] = y1 + fromVertical[i][1];
				nx[1] = x2 + fromVertical[i][2];
				ny[1] = y2 + fromVertical[i][3];
				if (0 <= nx[0] && nx[0] < n && 0 <= nx[1] && nx[1] < n
					&& 0 <= ny[0] && ny[0] < n && 0 <= ny[1] && ny[1] < n) {
					if (check(board, 1, i, cx, cy) == false) continue;
					if (board[nx[0]][ny[0]] == 1 || board[nx[1]][ny[1]] == 1) continue;
					tuple<int, int, int, int> t = setTuple(nx[0], ny[0], nx[1], ny[1]);
					if (visit.find(t) == visit.end()) {
						q.push(make_pair(dis + 1, t));
						visit.insert(t);
					}
				}
			}
		}
	}

	return dis;
}

int main() {
	vector<vector<int>> board = {
		{0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 0, 0, 1},
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 1, 1, 1, 0},
		{0, 1, 1, 1, 1, 1, 0},
		{0, 0, 0, 0, 0, 1, 1},
		{0, 0, 1, 0, 0, 0, 0}
	};

	cout << solution(board) << '\n';
}