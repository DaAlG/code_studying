using namespace std;
#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

int N;
char board[50][50];
int C_dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int C_dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
bool Visit[50][50][2];
int B_Shape, E_Shape;
pair<int, int> Start[3], End[3], B_Center, E_Center;

bool Change_Shape(int x, int y, int Shape)
{
    if (Shape == 0)
    {
        for (int i = 0; i < 8; i++)
        {
            if (i == 3 || i == 4) continue;

            int nx = x + C_dx[i];
            int ny = y + C_dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) return false;
            if (board[nx][ny] == '1') return false;
        }
    }
    else if (Shape == 1)
    {
        for (int i = 0; i < 8; i++)
        {
            if (i == 1 || i == 6) continue;

            int nx = x + C_dx[i];
            int ny = y + C_dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) return false;
            if (board[nx][ny] == '1') return false;
        }
    }
    return true;
}

int bfs(int a, int b) {
    queue<pair<pair<int, int>, pair<int, int>>> Q;
    Q.push(make_pair(make_pair(a, b), make_pair(B_Shape, 0)));
    Visit[a][b][B_Shape] = true;

    while (Q.empty() == 0)
    {
        bool F = false;

        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int S = Q.front().second.first;
        int Cnt = Q.front().second.second;
        Q.pop();

        if (x == E_Center.first && y == E_Center.second && S == E_Shape)
        {
            return Cnt;
        }

        if (S == 0) // 가로라면
        {
            int nx = x - 1;
            int ny = y;
            // Up
            if (nx >= 0 && ny - 1 >= 0 && ny + 1 < N && Visit[nx][ny][S] == false)
            {
                if (board[nx][ny] == '0' && board[nx][ny - 1] == '0' && board[nx][ny + 1] == '0')
                {
                    Visit[nx][ny][S] = true;
                    Q.push(make_pair(make_pair(nx, ny), make_pair(S, Cnt + 1)));
                }
            }

            nx = x + 1;
            ny = y;
            // Down
            if (nx < N && ny - 1 >= 0 && ny + 1 < N && Visit[nx][ny][S] == false)
            {
                if (board[nx][ny] == '0' && board[nx][ny - 1] == '0' && board[nx][ny + 1] == '0')
                {
                    Visit[nx][ny][S] = true;
                    Q.push(make_pair(make_pair(nx, ny), make_pair(S, Cnt + 1)));
                }
            }

            nx = x;
            ny = y - 1;
            int nny = y - 2;
            // Left
            if (nny >= 0 && Visit[nx][ny][S] == false)
            {
                if (board[nx][nny] == '0')
                {
                    Visit[nx][ny][S] = true;
                    Q.push(make_pair(make_pair(nx, ny), make_pair(S, Cnt + 1)));
                }
            }

            nx = x;
            ny = y + 1;
            nny = y + 2;
            // Right
            if (nny < N && Visit[nx][ny][S] == false)
            {
                if (board[nx][nny] == '0')
                {
                    Visit[nx][ny][S] = true;
                    Q.push(make_pair(make_pair(nx, ny), make_pair(S, Cnt + 1)));
                }
            }

            // Turn
            if (Change_Shape(x, y, S) == true && Visit[x][y][1] == false)
            {
                Visit[x][y][1] = true;
                Q.push(make_pair(make_pair(x, y), make_pair(1, Cnt + 1)));
            }
        }
        else    // 세로라면
        {
            int nx = x - 1;
            int ny = y;
            int nnx = x - 2;
            // Up
            if (nnx >= 0 && Visit[nx][ny][S] == false)
            {
                if (board[nnx][ny] == '0')
                {
                    Visit[nx][ny][S] = true;
                    Q.push(make_pair(make_pair(nx, ny), make_pair(S, Cnt + 1)));
                }
            }

            nx = x + 1;
            ny = y;
            nnx = x + 2;
            // Down
            if (nnx < N && Visit[nx][ny][S] == false)
            {
                if (board[nnx][ny] == '0')
                {
                    Visit[nx][ny][S] = true;
                    Q.push(make_pair(make_pair(nx, ny), make_pair(S, Cnt + 1)));
                }
            }

            nx = x;
            ny = y - 1;
            // Left
            if (ny >= 0 && nx - 1 >= 0 && nx + 1 < N && Visit[nx][ny][S] == false)
            {
                if (board[nx][ny] == '0' && board[nx - 1][ny] == '0' && board[nx + 1][ny] == '0')
                {
                    Visit[nx][ny][S] = true;
                    Q.push(make_pair(make_pair(nx, ny), make_pair(S, Cnt + 1)));
                }
            }

            nx = x;
            ny = y + 1;
            // Right
            if (ny < N && nx - 1 >= 0 && nx + 1 < N && Visit[nx][ny][S] == false)
            {
                if (board[nx][ny] == '0' && board[nx - 1][ny] == '0' && board[nx + 1][ny] == '0')
                {
                    Visit[nx][ny][S] = true;
                    Q.push(make_pair(make_pair(nx, ny), make_pair(S, Cnt + 1)));
                }
            }

            // Turn
            if (Change_Shape(x, y, S) == true && Visit[x][y][0] == false)
            {
                Visit[x][y][0] = true;
                Q.push(make_pair(make_pair(x, y), make_pair(0, Cnt + 1)));
            }
        }
    }
    return 0;
}

int Check_Shape(pair<int, int> S[3])
{
    if (S[0].first == S[1].first && S[1].first == S[2].first) return 0;
    else return 1;
}

int main() {
    int sx, sy;
    cin >> N;
    int cnt1 = 0, cnt2 = 0;
    char x;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'B')
            {
                Start[cnt1].first = i;
                Start[cnt1].second = j;
                cnt1++;

                board[i][j] = '0';
            }
            else if (board[i][j] == 'E')
            {
                End[cnt2].first = i;
                End[cnt2].second = j;
                cnt2++;

                board[i][j] = '0';
            }
        }
    }
    B_Center.first = Start[1].first;
    B_Center.second = Start[1].second;
    E_Center.first = End[1].first;
    E_Center.second = End[1].second;

    B_Shape = Check_Shape(Start);
    E_Shape = Check_Shape(End);

    int answer = bfs(B_Center.first, B_Center.second);
    cout << answer << '\n';
}