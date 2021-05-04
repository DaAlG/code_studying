#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 50
using namespace std;

int n, L, R;
int map[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool bfs(int stx, int sty)
{
    queue<pair<int, int>> q;
    q.push({stx, sty});
    visited[stx][sty] = true;
    int sum = map[stx][sty];

    // 연합을 이룬 칸
    vector<pair<int, int>> united;
    united.push_back({stx, sty});

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (visited[nx][ny]) continue;
            
            // 두 나라의 인구 차이가 L명 이상 R명 이하라면 국경선을 연다
            int diff = abs(map[x][y] - map[nx][ny]);
            if (diff >= L && diff <= R) {
                visited[nx][ny] = true;
                sum += map[nx][ny];
                united.push_back({nx, ny});
                q.push({ nx, ny });
            }
        }
    }

    if (united.size() == 1) 
        return false;

    // 연합을 이루고 있는 각 칸의 인구수 = (연합의 인구수) / (연합을 이루고 있는 칸의 개수)
    int newPop = sum / united.size();
    for (auto p : united) {
        map[p.first][p.second] = newPop;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> L >> R;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    int answer = 0;
    while (1) {
        memset(visited, false, sizeof(visited));

        bool check = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && bfs(i, j)) { // 인구 이동
                    if (check) check = false;
                }
            }
        }

        // 국경선이 열린 나라가 없다면 종료
        if (check)
            break;

        answer++;
    }
    cout << answer;
    return 0;
}