/*
스도쿠+도미노
유사하지만 처리를 하나만 더 해주면 됨
어떤 도미노 사용하는지 check 하는거만 하면 됨
*/
#include<iostream>
#include<cstring>
#include<tuple>

using namespace std;
int a[10][10];
bool c[10][10];
bool c2[10][10];
bool c3[10][10];
bool domino[10][10];
int n = 9;
int dx[] = { 0,1 };
int dy[] = { 1,0 };
pair<int, int> convert(string s) {
    return make_pair(s[0] - 'A', s[1] - '1');
}
int square(int x, int y) {
    return (x / 3) * 3 + (y / 3);
}
bool can(int x, int y, int num) {
    return c[x][num] == false && c2[y][num] == false && c3[square(x, y)][num] == false;

}
void check(int x, int y, int num, bool what) {
    c[x][num] = what;
    c2[y][num] = what;
    c3[square(x, y)][num] = what;
}
bool check_range(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}
bool go(int z) {
    if (z == 81) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j];
            }
            cout << '\n';
        }
        return true;
    }
    int x = z / n;
    int y = z % n;
    if (a[x][y] != 0) return go(z + 1);
    else {
        for (int k = 0; k < 2; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (!check_range(nx, ny)) continue;
            if (a[nx][ny] != 0) continue;
            for (int i = 1; i <= 9; i++) {
                for (int j = 1; j <= 9; j++) {
                    if (i == j) continue;
                    if (domino[i][j]) continue;
                    if (can(x, y, i) && can(nx, ny, j)) {
                        check(x, y, i, true);
                        check(nx, ny, j, true);
                        domino[i][j] = domino[j][i] = true;
                        a[x][y] = i;
                        a[nx][ny] = j;
                        if (go(z + 1)) return true;
                        check(x, y, i, false);
                        check(nx, ny, j, false);
                        domino[i][j] = domino[j][i] = false;
                        a[x][y] = 0;
                        a[nx][ny] = 0;
                    }
                }
            }
        }
    }
    return false;
}
int main() {
    int tc = 1;
    while (true) {
        memset(c, false, sizeof(c));
        memset(c2, false, sizeof(c2));
        memset(c3, false, sizeof(c3));
        memset(domino, false, sizeof(domino));
        memset(a, 0, sizeof(a));
        int m;
        cin >> m;
        if (m == 0) break;
        for (int i = 0; i < m; i++) {
            int n1, n2;
            string s1, s2;
            cin >> n1 >> s1 >> n2 >> s2;
            int x1, y1, x2, y2;
            tie(x1, y1) = convert(s1);//행렬 바꿔주기
            tie(x2, y2) = convert(s2);
            a[x1][y1] = n1;
            a[x2][y2] = n2;
            domino[n1][n2] = domino[n2][n1] = true;
            check(x1, y1, n1, true);
            check(x2, y2, n2, true);
        }
        for (int i = 1; i <= 9; i++) {
            string s;
            cin >> s;
            int x, y;
            tie(x, y) = convert(s);
            a[x][y] = i;
            check(x, y, i, true);
        }
        cout << "Puzzle" << tc << '\n';
        go(0);
        tc += 1;
    }
    return 0;
}