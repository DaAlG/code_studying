#include <string>
#include <vector>
#include <queue>
#define INF 0x3f3f3f

using namespace std;

struct Road {
    int x, y, cost, dir;
};

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int solution(vector<vector<int>> board) {
    int n = board.size();

    queue<Road> q;
    q.push({ 0, 0, 0, 10});
    board[0][0] = 1;

    int answer = INF;
    while (!q.empty()) {
        Road r = q.front();
        q.pop();

        if (r.x == n - 1 && r.y == n - 1) {
            answer = min(answer, r.cost);
            continue;
        }

        for (int d = 0; d < 4; d++) {
            if (abs(d - r.dir) == 2) continue;
            
            int nx = r.x + dx[d];
            int ny = r.y + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny] == 1) continue;

            int nCost = r.cost;
            if ((r.x == 0 && r.y == 0) || r.dir == d)
                nCost += 100;
            else
                nCost += 600;

            if (board[nx][ny] == 0 ||  board[nx][ny] >= nCost) {
                q.push({ nx, ny, nCost, d });
                board[nx][ny] = nCost;
            }
        }
    }

    return answer;
}