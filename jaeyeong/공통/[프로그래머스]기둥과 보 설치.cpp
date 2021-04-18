using namespace std;
#include <iostream>
#include <string>
#include <vector>

int board[102][102][2]; //[0]은 기둥 유무, [1]은 보 유무

bool possible(int x, int y, int a) {
	if (a == 0) { // 기둥 
		if(!y || (y-1 >= 0 && board[x][y-1][0]) ||
			board[x][y][1] ||
			(x-1 >= 0 && board[x-1][y][1]))
			return true; 
	} else{ // 보 
		if((y-1 >= 0 && board[x][y-1][0]) ||
			(y-1 >= 0 && board[x+1][y-1][0]) ||
			(x-1 >= 0 && board[x-1][y][1] && board[x+1][y][1] ))
			return true; 
	} 
	return false;
}


vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	int m = build_frame.size();
	for (int i = 0; i < m; i++) {
		int x = build_frame[i][0];
		int y = build_frame[i][1];
		int a = build_frame[i][2]; //0이면 기둥, 1이면 보
		int b = build_frame[i][3]; //0이면 삭제, 1이면 설치
		if (b == 0) {
			board[x][y][a] = 0;
			for (int i = 0; i <= n; i++){ 
				for (int j = 0; j <= n; j++) { 
					for (int k = 0; k < 2; k++) { 
						if (board[x][y][a] == 1) break;
						if (board[i][j][k] == 1 && possible(i, j, k)==false)
							board[x][y][a] = 1;
					} 
				} 
			}

		}
		else if (b == 1) {
			if (possible(x, y, a) == true)
				board[x][y][a] = 1;
		}
	}

	vector<vector<int>> answer;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k < 2; k++) {
				if (board[i][j][k] == 1) {
					vector<int> v = { i,j,k };
					answer.push_back(v);
				}

			}
		}
	}
	return answer;
}

int main() {
	int n = 5;
	vector<vector<int>> build_frame = { {1, 0, 0, 1}, {1, 1, 1, 1}, {2, 1, 0, 1}, {2, 2, 1, 1}, {5, 0, 0, 1}, {5, 1, 0, 1}, {4, 2, 1, 1}, {3, 2, 1, 1} };
	vector<vector<int>> ans = solution(n, build_frame);
	int size = ans.size();
	cout << '[';
	for (int i = 0; i < size; i++) {
		cout << '[';
		for (int j = 0; j < 3; j++) {
			cout << ans[i][j];
			if (j != 2)
				cout << ',';
		}
		cout << ']';
		if (i != size - 1)
			cout << ',';
	}
	cout << ']';
}