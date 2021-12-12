/*
 * BOJ 11559 Puyo Puyo
 */

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;

char map[12][7];
bool visited[12][6];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool isWall(int x, int y)
{
    return x < 0 || x >= 12 || y < 0 || y >= 6;
}

bool bfs(int stx, int sty)
{
    queue<pii> q;
    vector<pii> blocks;

    q.push({ stx, sty });
    visited[stx][sty] = true;

    char color = map[stx][sty];
    while (!q.empty()) {
        auto [x, y] = q.front();
        blocks.push_back({ x, y });
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isWall(nx, ny) || visited[nx][ny] || map[nx][ny] != color)
                continue;

            visited[nx][ny] = true;
            q.push({ nx, ny });
        }
    }

    if (blocks.size() >= 4) {
        for (auto &[x, y] : blocks) {
            map[x][y] = '.';
        }
        return true;
    }
    return false;
}

void down() {
    for (int i = 10; i >= 0; i--) {
        for (int j = 0; j < 6; j++) {
            if (map[i][j] != '.') {
                int idx = i;
                while (idx + 1 < 12 && map[idx + 1][j] == '.') {
                    swap(map[idx][j], map[idx + 1][j]);
                    idx++;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (auto &m : map) {
        cin >> m;
    }

    int answer = 0;
    while (true) {
        bool check = false;
        memset(visited, false, sizeof(visited));
        for (int i = 11; i >= 0; i--) {
            for (int j = 0; j < 6; j++) {
                if (map[i][j] != '.' && !visited[i][j] && bfs(i, j)) {
                    check = true;
                }
            }
        }

        if (!check)
            break;

        answer++;
        down();
    }
    cout << answer;
    return 0;
}
