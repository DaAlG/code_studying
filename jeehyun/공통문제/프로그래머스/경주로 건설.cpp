#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define INF 0x3f3f3f

using namespace std;

struct Road {
    int x, y, cost, dir;
    Road(int x, int y, int cost, int dir)
        : x(x), y(y), cost(cost), dir(dir) {};
};

int dist[25][25][4];

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

struct cmp {
    bool operator()(Road& a, Road& b) {
        return a.cost > b.cost;
    }
};

int solution(vector<vector<int>> board) {
    int n = board.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++)
                dist[i][j][k] = INF;
        }
    }

    priority_queue<Road, vector<Road>, cmp> pq;

    for (int i = 0; i < 4; i++) {
        pq.push(Road(0, 0, 0, i));
        dist[0][0][i] = 0;
    }

    while (!pq.empty()) {
        int x = pq.top().x;
        int y = pq.top().y;
        int cost = pq.top().cost;
        int dir = pq.top().dir;
        pq.pop();

        for (int d = 0; d < 4; d++) {
            // 이전에 왔던 칸으로 돌아가는 경우
            if (abs(dir - d) == 2) continue;

            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny]) continue;

            int nCost = dist[x][y][dir] + 100;
            if (dir != d) // 커브
                nCost += 500;

            if (dist[nx][ny][d] > nCost) {
                dist[nx][ny][d] = nCost;
                pq.push(Road(nx, ny, nCost, d));
            }
        }
    }
    
    int answer = INF;
    for (int i = 0; i < 4; i++) {
        answer = min(answer, dist[n - 1][n - 1][i]);
    }

    return answer;
}


int main()
{
    vector<vector<int>> board = { { 0, 0, 0, 0, 0 } ,{ 0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0},{1, 0, 0, 0, 1},{0, 1, 1, 0, 0}};
    cout << solution(board);
    return 0;
}