#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
#define INF 0x3f3f3f

using namespace std;

int cost[25][25];

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int solution(vector<vector<int>> board) {
    int n = board.size();
    memset(cost, INF, sizeof(cost));

    queue<pair<pair<int, int>, int>> q;
    q.push({ {0, 0}, -1 });
    cost[0][0] = 0;

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dir = q.front().second;
        q.pop();

        if (x == n - 1 && y == n - 1)
            continue;

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny]) continue;

            int nCost = 100;
            if (dir != -1 && d % 2 != dir)
                nCost += 500;

            if (cost[nx][ny] >= cost[x][y] + nCost) {
                q.push({ {nx, ny}, d % 2 });
                cost[nx][ny] = cost[x][y] + nCost;
            }
        }
    }

    return cost[n - 1][n - 1];
}

int main()
{
    vector<vector<int>> board = { {0,0,0,0,0,0} ,{0,1,1,1,1,0},
        {0, 0, 1, 0, 0, 0},{1, 0, 0, 1, 0, 1},{0, 1, 0, 0, 0, 1},{0, 0, 0, 0, 0, 0} };
    cout << solution(board);
    return 0;
}