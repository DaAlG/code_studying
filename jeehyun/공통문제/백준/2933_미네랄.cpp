/*
 * BOJ 2933 미네랄
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 101
#define endl "\n"
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;

int r, c, n;
string map[MAX];
int check[MAX][MAX];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

vector<pii> mineral;

void destroy(int row, int flag)
{
    if (flag == 0) {
        for (int i = 0; i < c; i++) {
            if (map[row][i] == 'x') {
                map[row][i] = '.';
                break;
            }
        }
    }
    else {
        for (int i = c - 1; i >= 0; i--) {
            if (map[row][i] == 'x') {
                map[row][i] = '.';
                break;
            }
        }
    }
}

bool isNotWall(int x, int y)
{
    return x >= 1 && x <= r && y >= 0 && y < c;
}

void dfs(int x, int y, int num)
{
    if (check[x][y] != 0) return;

    check[x][y] = num;
    mineral.push_back({ x, y });

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (isNotWall(nx, ny) && map[nx][ny] == 'x') {
            dfs(nx, ny, num);
        }
    }
}

bool cmp(pii a, pii b)
{
    if (a.x == b.x)
        return a.y < b.y;
    return a.x > b.x;
}

bool possible(int cnt)
{
    // 다른 클러스터를 만나거나 cnt만큼 이동할 수 있는지 확인
    for (auto [x, y] : mineral) {
        if (check[x + cnt][y] != check[x][y] && map[x + cnt][y] == 'x')
            return false;
    }
    return true;
}

void downwards()
{
    sort(mineral.begin(), mineral.end(), cmp);

    auto [x, y] = mineral[0];
    int cnt = 0;
    while (x + 1 <= r && possible(cnt + 1)) {
        x++;
        cnt++;
    }

    if (cnt == 0) return;

    for (auto &[x, y] : mineral) {
        swap(map[x][y], map[x + cnt][y]);
        swap(check[x][y], check[x + cnt][y]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;
    for (int i = 1; i <= r; i++) {
        cin >> map[i];
    }

    cin >> n;
    for (int i = 0, h; i < n; i++) {
        cin >> h;

        destroy(r - h + 1, i % 2);

        memset(check, 0, sizeof(check));

        int num = 1;
        for (int j = r; j > 0; j--) {
            for (int k = 0; k < c; k++) {
                if (map[j][k] == 'x' && check[j][k] == 0) {
                    dfs(j, k, num++);
                    downwards();
                    mineral.clear();
                }
            }
        }
    }

    for (int i = 1; i <= r; i++) {
        cout << map[i];
        if (i < r) cout << endl;
    }
    return 0;
}
