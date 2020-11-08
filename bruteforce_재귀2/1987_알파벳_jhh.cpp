/*
세로 R칸, 가로 C칸으로 된 표 모양의 보드가 있다
보드의 각 칸에는 대문자 알파벳이 하나씩 적혀 있고, 좌측 상단 칸 (1해 1열) 에는 말이 놓여 있다.
말은 상하좌우로 인접한 네 칸 중의 한 칸으로 이동할 수 있다.
같은 알파벳이 적힌 칸을 두 번 지날 수 없다.
좌측 상단에서 시작해서, 말이 최대한 몇 칸을 지날 수 있는지를 구할 수 있는 문제

*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int go(vector<string>& board, vector<bool>& check, int x, int y) {
    /*
    board: 보드, check: 방문한 알파벳, x,y: 현재 위치, cnt: 방문한 칸의 수

    */
    int ans = 0;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k]; //nx 행 ny열로 이동
        if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
            if (check[board[nx][ny] - 'A'] == false) {//같은 칸 못지나 가니까 처리해줘야 함
                check[board[nx][ny] - 'A'] = true;
                int next = go(board, check, nx, ny);
                if (ans < next) {
                    ans = next;
                }
                check[board[nx][ny] - 'A'] = false; //원래상태로 돌아옴
            }
        }
    }
    return ans + 1;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<string> board(n);
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    vector<bool> check(26);
    check[board[0][0] - 'A'] = true;
    cout << go(board, check, 0, 0) << '\n';
    return 0;
}
