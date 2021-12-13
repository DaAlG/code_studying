using namespace std;
#include <iostream>
#include <vector>

int board[9][9];
vector<pair<int, int>> blank;
bool answer = false;

bool possible(int value, int idx) {
	int x = blank[idx].first;
	int y = blank[idx].second;
	for (int i = 0; i < 9; i++) {
		if (board[x][i] == value)
			return false;
		if (board[i][y] == value)
			return false;
	}
	//0 3 6
	int squareX = (x / 3) * 3;
	int squareY = (y / 3) * 3;
	for (int i = squareX; i < squareX + 3; i++)
		for (int j = squareY; j < squareY + 3; j++)
			if (board[i][j] == value)
				return false;
	return true;
}
void solution(int idx) {
	if (answer == true) return;
	if (idx == blank.size()) {
		answer = true;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << board[i][j] << ' ';
			}
			cout << '\n';
		}
		return;
	}
	for (int i = 1; i <= 9; i++) {
		if (possible(i, idx) == true) {
			int x = blank[idx].first;
			int y = blank[idx].second;
			board[x][y] = i;
			solution(idx + 1);
			if (answer == true) return;
			board[x][y] = 0;
		}
	}
}
int main(){
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0)
				blank.push_back(make_pair(i, j));
		}
	}
	solution(0);

}