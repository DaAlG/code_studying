#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#define INF 0x3f3f3f

using namespace std;

vector<pair<int, int>> card[7];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool inRange(int x, int y) {
    return x >= 0 && y >= 0 && x < 4 && y < 4;
}

int bfs(vector<vector<int>>& board, pair<int, int> start, pair<int, int> dest) {
    vector<vector<bool>> visited(4, vector<bool>(4));
    queue<pair<pair<int, int>, int>> q;
    q.push({ start, 0 });
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second;
        q.pop();

        if (x == dest.first && y == dest.second) {
            return d;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!inRange(nx, ny)) continue;

            // 방향키로 이동
            if (!visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({ {nx, ny}, d + 1 });
            }

            if (board[nx][ny]) continue;

            // ctrl + 방향키
            while (inRange(nx + dx[i], ny + dy[i])) {
                nx += dx[i];
                ny += dy[i];

                if (board[nx][ny])
                    break;
            }

            if (!visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({ {nx, ny}, d + 1 });
            }
        }
    }
}

int solution(vector<vector<int>> board, int r, int c) {
    int n = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] != 0) {
                card[board[i][j]].push_back({ i, j });
                n++;
            }
        }
    }
    n /= 2;

    vector<int> order;
    for (int i = 1; i <= n; i++) {
        order.push_back(i);
    }

    int answer = INF;
    do {
        // XA, XB 순서를 비트마스크로 정한다
        for (int k = 0; k < (1 << n); k++) {
            int total = 0;
            pair<int, int> prev = { r, c };

            vector<vector<int>> new_board(4, vector<int>(4));
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    new_board[i][j] = board[i][j];
                }
            }

            for (int i = 0; i < order.size(); i++) {
                int start = k & (1 << i) ? 1 : 0;

                pair<int, int> a = card[order[i]][start];
                pair<int, int> b = card[order[i]][!start];

                total += bfs(new_board, prev, a) + 1;
                total += bfs(new_board, a, b) + 1;
                new_board[a.first][a.second] = new_board[b.first][b.second] = 0;

                prev = b;
            }
            answer = min(answer, total);
        }
    } while (next_permutation(order.begin(), order.end()));

    return answer;
}