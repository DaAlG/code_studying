#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) 
{
    int answer = 0;
    vector<int> basket;

    for (int i = 0; i < moves.size(); i++) {
        int c = moves[i] - 1;
        int next = 0;
        
        // 가장 위에 있는 인형을 찾는다
        for (int j = 0; j < board.size(); j++) {
            if (board[j][c]) { // 인형을 꺼내면 빈칸이 된다
                next = board[j][c];
                board[j][c] = 0;
                break;
            }
        }

        if (next) { // 인형을 꺼냈을 경우
            // 바구니에 같은 인형이 있으면 없앤다
            if (!basket.empty() && basket.back() == next) {
                answer++;
                while (basket.back() == next) {
                    answer++;
                    basket.pop_back();
                }
            }
            else // 같은 인형이 아닐 경우 바구니에 넣는다
                basket.push_back(next);
        }
    }

    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> board = {{0, 0, 0, 0, 0}, {0, 0, 1, 0, 3}, {0, 2, 5, 0, 1}, {4, 2, 4, 4, 2}, {3, 5, 1, 3, 1}};
    vector<int> moves = { 1, 5, 3, 5, 1, 2, 1, 4 };
    cout << solution(board, moves);
}