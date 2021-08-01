#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n = 16;
char map[16][16];
bool visited[16][16];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool bfs(pair<int, int> start)
{
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 도착점에 왔으므로 종료
        if (map[x][y] == '3')
            return true;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 벽이 아닌 곳으로 이동한다
            if (map[nx][ny] != '1' && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({ nx, ny });
            }
        }
    }
    return false;
}

int main(int argc, char** argv)
{
    int T = 10;
    for (int test_case = 1; test_case <= T; ++test_case) {
        cin >> test_case;
        pair<int, int> start;
        for (int i = 0; i < n; i++) {
            cin >> map[i];
            for (int j = 0; j < n; j++) {
                if (map[i][j] == '2') start = { i, j };
            }
        }
        cout << "#" << test_case << " " << bfs(start) << "\n";
    }
    return 0;
}