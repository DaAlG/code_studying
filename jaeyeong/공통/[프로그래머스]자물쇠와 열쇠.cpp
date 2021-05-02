#include <iostream>
#include <string>
#include <vector>

using namespace std;
int n, m;
int boardsize;

vector<vector<int>> rot90(vector<vector<int>> key) {
    vector<vector<int>> nkey(m, vector <int>(m, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            nkey[j][m - i - 1] = key[i][j];
        }
    }
    return nkey;
}

bool check(int x, int y, vector<vector<int>> key, vector<vector<int>> board) {
    //(x, y)를 시작점으로 열쇠를 자물쇠에 맞추기!

   //key를 더한다
    for (int i = x; i < x + m; i++) {
        for (int j = y; j < y + m; j++) {
            board[i][j] += key[i - x][j - y];
        }
    }
    //좌물쇠 부분 확인
    for (int i = m - 1; i <= boardsize - m; i++) {
        for (int j = m - 1; j <= boardsize - m; j++) {
            if (board[i][j] == 1) continue;
            //1이 아니라면 바로 false를 리턴
            return false;
        }
    }
    return true;
}


bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    n = lock.size();
    m = key.size();
    boardsize = n + (m - 1) * 2;

    vector<vector<int>> board(boardsize, vector<int>(boardsize, 0));

    for (int i = m - 1; i <= boardsize - m; i++) {
        for (int j = m - 1; j <= boardsize - m; j++) {
            board[i][j] = lock[i - m + 1][j - m + 1];
        }
    }

    for (int r = 0; r < 4; r++) {
        for (int i = 0; i <= boardsize - m; i++) {
            for (int j = 0; j < boardsize - m; j++) {
                if (check(i, j, key, board)) {
                    answer = true;
                    return answer;
                }
            }
        }
        key = rot90(key);
    }

    return answer = false;
}

int main() {
    vector<vector<int>> key = { {0,0,0}, {1,0,0}, {0,1,1} };
    vector<vector<int>> lock = { {1,1,1}, {1,1,0}, {1,0,1} };
    cout << solution(key, lock);
}