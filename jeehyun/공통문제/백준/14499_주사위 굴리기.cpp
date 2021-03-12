#include <iostream>
#include <vector>
using namespace std;

int n, m;
int map[21][21];
vector<int> dice(6);

int dx[] = { 0, 0, -1, 1}; // 동서북남
int dy[] = { 1, -1, 0, 0};

void rollDice(int dir)
{
    switch (dir) {
    case 1: // 동
        dice = { dice[3], dice[1], dice[0], dice[5], dice[4], dice[2] };
        break;
    case 2: // 서
        dice = { dice[2], dice[1], dice[5], dice[0], dice[4], dice[3] };
        break;
    case 3: // 북
        dice = { dice[4], dice[0], dice[2], dice[3], dice[5], dice[1] };
        break;
    case 4: // 남
        dice = { dice[1], dice[5], dice[2], dice[3], dice[0], dice[4] };
        break;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, y, k;
    cin >> n >> m >> x >> y >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    }

    int dir;

    for (int i = 0; i < k; i++) {
        cin >> dir;

        int nx = x + dx[dir - 1];
        int ny = y + dy[dir - 1];

        // 지도의 바깥일 경우 명령 무시
        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            continue;

        rollDice(dir);

        // 이동한 칸에 쓰여있는 수가 0이 아닌 경우에는 칸에 쓰여 있는 수를 주사위의 바닥면으로 복사
        if (map[nx][ny]) {
            dice[5] = map[nx][ny];
            map[nx][ny] = 0;
        }
        else { // 0일 경우 주사위의 바닥면에 쓰여 있는 수를 칸에 복사
            map[nx][ny] = dice[5];
        }

        // 주사위 상단에 쓰여있는 값 출력
        cout << dice[0] << '\n';

        x = nx;
        y = ny;
    }

    return 0;
}