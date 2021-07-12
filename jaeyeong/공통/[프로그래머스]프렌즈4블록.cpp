#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<pair<int, int>> to_delete(int m, int n, vector<string> board) {
    vector<pair<int, int>> res;
    for (int i = 0; i < m-1; i++) {
        for (int j = 0; j < n-1; j++) {
            if (board[i][j] == '0') continue;
            if (board[i][j] == board[i][j + 1] && 
                board[i][j] == board[i + 1][j] && 
                board[i][j] == board[i + 1][j + 1]) {
                res.push_back(make_pair(i, j));
            }
        }
    }
    return res;
}
int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<pair<int, int>> del;
    stack<char> col_node;
    while ((del = to_delete(m, n, board)).size() != 0) {
        //do_delete
        for (int i = 0; i < del.size(); i++) {
            int x = del[i].first, y = del[i].second;
            board[x][y] = '0';
            board[x + 1][y] = '0';
            board[x][y + 1] = '0';
            board[x + 1][y + 1] = '0';
        }
        //내려오기
        for (int j = 0; j < n; j++) { //열마다 돌며 체크
            for (int i = 0; i < m; i++) {
                if (board[i][j] != '0')
                    col_node.push(board[i][j]);
            }
            for (int i = m - 1; 0 <= i; i--) {
                if (col_node.empty()) board[i][j] = '0';
                else {
                    board[i][j] = col_node.top();
                    col_node.pop();
                }
            }

        }
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (board[i][j] == '0') answer++;
    return answer;
}