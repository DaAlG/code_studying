using namespace std;
#include <iostream>
#include <cstring>
#include <vector>

int board[9][9];
vector<pair<int,int>> v;
int m;
bool done = false;

bool check(int x, int y, int k) {
	//1.가로, 세로
	for (int i = 0; i < 9; i++) {
		if (board[x][i] == k) return false;
		if (board[i][y] == k) return false;
	}
	//3. 사각형
	int sx = (x / 3)*3, sy = (y / 3)*3;
	for (int i = sx; i < sx+3; i++) {
		for (int j = sy; j < sy+3; j++) {
			if (board[i][j] == k) return false;
		}
	}
	return true;
}
void solve(int idx) {
	if (done == true) return;
	if (idx == m) {
		done = true;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << board[i][j];
			}
			cout << '\n';
		}
		return;
	}
	int x = v[idx].first, y = v[idx].second;
	for (int i = 1; i <= 9; i++) {
		if (check(x,y,i)) {
			board[x][y] = i;
			solve(idx + 1);
			if (done == true) return;
			board[x][y] = 0;
		}
	}
}
int main() {
	char x;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> x;
			board[i][j] = x-'0';
			if (board[i][j] == 0)
				v.push_back(make_pair(i,j));
		}
	}
	m = v.size();
	solve(0);
}