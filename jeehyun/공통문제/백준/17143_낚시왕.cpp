/*
 * BOJ 17143 낚시왕
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;

struct Shark{
    int speed, dir, z;
    Shark(int speed, int dir, int z) : speed(speed), dir(dir), z(z) { }
};

int n, m, cnt;
int map[MAX][MAX];
int nMap[MAX][MAX];
vector<Shark> sharks;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int getDir(int d)
{
    if (d == 1) return 0; // 위
    else if (d == 2) return 2; // 아래
    else if (d == 3) return 1; // 오른쪽
    else return 3; // 왼쪽
}

bool isWall(int x, int y)
{
    return x <= 0 || x > n || y <= 0 || y > m;
}

int inplace(int x, int y, int d)
{
    if (d % 2 == 0)
        return (n - 1) * 2;
    else
        return (m - 1) * 2;
}

void move()
{
    for (int i = 1; i <= n; i++) {
        fill_n(nMap[i], m + 1, 0);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (map[i][j] != 0) {
                int idx = map[i][j];
                int d = sharks[idx].dir;

                int x = i;
                int y = j;
                int nx = x;
                int ny = y;

                // 제자리로 돌아오기 위해 이동해야 하는 횟수
                int inp = inplace(x, y, sharks[idx].dir);
                int s = sharks[idx].speed % inp;

                for (int k = 0; k < s; k++) {
                    nx = x + dx[d];
                    ny = y + dy[d];
                    if (isWall(nx, ny)) {
                        d = (d + 2) % 4;
                        nx = x + dx[d];
                        ny = y + dy[d];
                    }
                    x = nx;
                    y = ny;
                }

                if (nMap[nx][ny] == 0 || sharks[nMap[nx][ny]].z < sharks[idx].z) {
                    nMap[nx][ny] = idx;
                    sharks[idx].dir = d;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j =1 ; j<= m; j++) {
            map[i][j] = nMap[i][j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> cnt;

    sharks.push_back(Shark(-1, -1, -1));

    for (int i = 1; i <= cnt; i++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        map[r][c] = i;
        sharks.push_back(Shark(s, getDir(d), z));
    }

    int answer = 0;
    for (int j = 1; j <= m; j++) {
        // 땅에서 가장 가까운 상어를 잡는다
        for (int i = 1; i <= n; i++) {
            if (map[i][j] != 0) {
                answer += sharks[map[i][j]].z;
                map[i][j] = 0;
                break;
            }
        }

        // 상어 이동
        move();
    }
    cout << answer;
    return 0;
}