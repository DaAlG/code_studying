/*
 * BOJ 18808 스티커 붙이기
 */

#include <iostream>
using namespace std;

int n, m, k, r, c;
int note[40][40];
int sticker[10][10];

void rotate()
{
    int tmp[10][10];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            tmp[j][r - i - 1] = sticker[i][j];
        }
    }

    swap(r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            sticker[i][j] = tmp[i][j];
        }
    }
}

bool possible(int x, int y)
{
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (sticker[i][j] == 1 && note[x + i][y + j] != 0)
                return false;
        }
    }
    return true;
}

int attach(int x, int y)
{
    int cnt = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (sticker[i][j] == 1) {
               note[x + i][y + j] = 1;
               cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;

    int answer = 0;
    while (k--) {
        cin >> r >> c;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> sticker[i][j];
            }
        }

        // 스티커 붙일 위치 찾기
        bool attached = false;
        for (int s = 0; s < 4; s++) {
            if (attached) break;
            for (int i = 0; i <= n - r; i++) {
                if (attached) break;
                for (int j = 0; j <= m - c; j++) {
                    if (possible(i, j)) {
                        attached = true;
                        answer += attach(i, j);
                        break;
                    }
                }
            }
            rotate();
        }
    }
    cout << answer;
    return 0;
}
