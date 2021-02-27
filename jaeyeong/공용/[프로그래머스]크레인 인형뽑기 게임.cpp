using namespace std;
#include <iostream>
#include <string>
#include <vector>


int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0, n =board.size(), m = board[0].size();
    int top[100] = { 0 }, height[100] = {0};
    vector<int> basket;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] != 0) {
                if(top[j]==0)
                    top[j] = board[i][j];
                height[j]++;
            }
        }
    }
    int back = -1;
    while (moves.empty() == false) {
        if (top[moves[0] - 1] == -100) {
            moves.erase(moves.begin());
            continue;
        }

        if (back == top[moves[0]-1]) {
            basket.erase(basket.begin()+basket.size()-1);
            answer += 2;
        }
        else {
            basket.push_back(top[moves[0]-1]);
        }

        back = basket.back();
        height[moves[0]-1]--;
        if (height[moves[0] - 1] == 0)
            top[moves[0] - 1] = -100;
        else
            top[moves[0]-1] = board[n - height[moves[0]-1]][moves[0]-1];
        moves.erase(moves.begin());
    }
    return answer;
}

int main() {
    vector<vector<int>> board = { {0,0,0,0,0}, {0,0,1,0,3}, {0,2,5,0,1}, {4,2,4,4,2}, {3,5,1,3,1} };
    vector<int> moves = { 1,5,3,5,1,2,1,4 };

    cout << solution(board, moves) << '\n';
}