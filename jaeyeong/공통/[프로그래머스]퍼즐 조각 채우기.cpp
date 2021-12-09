using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define MAX 51


int visit[MAX][MAX];
int dir[4][2] = { {0,1},{0,-1},{1,0},{0,-1} };
int n;
vector<vector<pair<int, int>>> allPairs;

bool inRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}
void dfs(int x, int y, vector<pair<int, int>>& block, vector<vector<int>> table) {
	if (visit[x][y]) return;
	if (table[x][y] == 0) return;
	visit[x][y] = 1;
	block.push_back(make_pair(x,y));
	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if (!inRange(nx, ny)) continue;
		dfs(nx, ny, block, table);
	}
}
bool solve(vector<vector<int>>& board, vector<pair<int, int>> block) {
	int n = board.size();
	for (int r = -n + 1; r < n; r++) {
		for (int c = -n + 1; c < n; c++) {
			vector<pair<int, int>> fitblock;
			for (auto b : block) fitblock.push_back({ b.first + r, b.second + c });

			int cnt = 0;
			for (int i = 0; i < fitblock.size(); i++) {
				pair<int, int> cur = fitblock[i];
				if (cur.first < 0 || cur.second < 0 || cur.first >= n || cur.second >= n) break;
				if (board[cur.first][cur.second] == 1) break;
				cnt++;
			}
			if (cnt == fitblock.size()) {
				bool fit = true;
				for (auto a : fitblock) board[a.first][a.second] = 1;
				for (int i = 0; i < fitblock.size(); i++) {
					pair<int, int> cur = fitblock[i];
					for (int d = 0; d < 4; d++) {
						int ny = cur.first + dir[d][0], nx = cur.second + dir[d][1];
						if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
						if (board[ny][nx] == 0) {
							fit = false; break;
						}
					}
					if (fit == false) break;
				}
				if (fit == false) {
					for (auto a : fitblock) board[a.first][a.second] = 0;
				}
				else return true;
			}
		}
	}
	return false;
}
int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
	int answer = 0;
	n = game_board.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (table[i][j] == 1) {
				//dfs로 테이블 위 조각들을 모두 vector에 담고 방문 배열 처리를 한다.
				vector<pair<int, int>> block;
				dfs(i, j, block, table);
				if (block.size()) allPairs.push_back(block);
			}
		}
	}

	vector<vector<int>> rotateBoard(n, vector<int>(n, 0));
	vector<bool> pairsVis(allPairs.size(), false);
	for (int rot = 0; rot < 4; rot++) {
		// rotate
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < n; c++) {
				rotateBoard[r][c] = game_board[c][n - r - 1];
			}
		}

		for (int i = 0; i < allPairs.size(); i++) {
			if (pairsVis[i] == 0 && solve(rotateBoard, allPairs[i])) {
				answer += allPairs[i].size();
				pairsVis[i] = 1;
			}
		}

		// rotate
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < n; c++) {
				game_board[r][c] = rotateBoard[r][c];
			}
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<vector<int>> game_board = { {1, 1, 0, 0, 1, 0},{0, 0, 1, 0, 1, 0},{0, 1, 1, 0, 0, 1},{1, 1, 0, 1, 1, 1},{1, 0, 0, 0, 1, 0},{0, 1, 1, 1, 0, 0} };
	vector<vector<int>> table = { {1, 0, 0, 1, 1, 0},{1, 0, 1, 0, 1, 0},{0, 1, 1, 0, 1, 1},{0, 0, 1, 0, 0, 0},{1, 1, 0, 1, 1, 0},{0, 1, 0, 0, 0, 0 } };
	cout << solution(game_board, table) << '\n';
}