#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct robot {
    int x1;
    int y1;
    int x2;
    int y2;
};

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

vector<robot> getNextPos(vector<vector<int>> board, robot cur) {
    vector<robot> res;

    for (int i = 0; i < 4; i++) { // 상하좌우
        robot next = { cur.x1 + dx[i], cur.y1 + dy[i], cur.x2 + dx[i], cur.y2 + dy[i] };

        if (board[next.x1][next.y1] == 0 && board[next.x2][next.y2] == 0)
            res.push_back(next);
    }

    if (cur.x1 == cur.x2) { // 가로 방향 회전
        for (int i = 0; i < 2; i++) {
            if (board[cur.x1 + dx[i]][cur.y1 + dy[i]] == 0 && board[cur.x2 + dx[i]][cur.y2 + dy[i]] == 0) {
                res.push_back({ cur.x1, cur.y1, cur.x1 + dx[i], cur.y1 + dy[i] });
                res.push_back({ cur.x2, cur.y2, cur.x2 + dx[i], cur.y2 + dy[i] });
            }
        }
    }
    else if (cur.y1 == cur.y2) { // 세로 방향 회전
        for (int i = 2; i < 4; i++) {
            if (board[cur.x1 + dx[i]][cur.y1 + dy[i]] == 0 && board[cur.x2 + dx[i]][cur.y2 + dy[i]] == 0) {
                res.push_back({ cur.x1, cur.y1, cur.x1 + dx[i], cur.y1 + dy[i] });
                res.push_back({ cur.x2, cur.y2, cur.x2 + dx[i], cur.y2 + dy[i] });
            }
        }
    }

    return res;
}

int solution(vector<vector<int>> board) {
    int answer = 0;

    int n = board.size();
    vector<vector<int>> new_board(n + 2, vector<int>(n + 2, 1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            new_board[i + 1][j + 1] = board[i][j];
        }
    }

    queue<pair<robot, int>> q;
    vector<robot> visited;

    robot start = { 1, 1, 1, 2 };
    q.push({ start, 0 });
    visited.push_back(start);

    while (!q.empty()) {
        robot cur = q.front().first;
        int dist = q.front().second;
        q.pop();

        if ((cur.x1 == n && cur.y1 == n) || (cur.x2 == n && cur.y2 == n)) {
            answer = dist;
            break;
        }

        vector<robot> nextPos = getNextPos(new_board, cur);
        for (robot next : nextPos) {
            bool check = true;

            for (int i = 0; i < visited.size(); i++) {
                if (visited[i].x1 == next.x1 && visited[i].y1 == next.y1 && visited[i].x2 == next.x2 && visited[i].y2 == next.y2) {
                    check = false;
                    break;
                }
            }

            if (check) {
                visited.push_back(next);
                q.push({ next, dist + 1 });
            }
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> board = { {0, 0, 0, 1, 1}, {0, 0, 0, 1, 0}, {0, 1, 0, 1, 1}, {1, 1, 0, 0, 1}, {0, 0, 0, 0, 0} };
    cout << solution(board);
    return 0;
}