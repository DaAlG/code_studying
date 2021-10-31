/*
 * BOJ 23291 어항 정리
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 101
#define endl "\n"
#define fi first
#define se second
using namespace std;
typedef pair<int, int> pii;

int n, k;
int fish[MAX];
int air[MAX][MAX], air2[MAX][MAX];
vector<pii> roll, fold;
vector<pii> rollBack, foldBack;

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };

bool isWall(int x, int y, int size)
{
    return x < 0 || x >= size || y < 0 || y >= size;
}

bool cmp(pii a, pii b)
{
    if (a.se == b.se)
        return a.fi > b.fi;
    return a.se < b.se;
}

void findPoints()
{
    int size = (int)sqrt((double)n);
    int x = size / 2;
    int y = size / 2;
    int limit = 1;
    if (size <= 2) limit = 0;
    int cnt = 0;

    int start = () % 4;
    int d = start;


    for (int i = 0; i < size * size; i++) {
        roll.push_back({ x, y });

        int nx = x + dx[d];
        int ny = y  + dy[d];
        if (i < (size * size - 1) && isWall(nx, ny, size) || cnt == limit) {
            d  = (d + 1) % 4;
            if (d == 0 || d == 2)
                limit++;
            cnt = -1;
            nx = x + dx[d];
            ny = y + dy[d];
        }
        cnt++;
        x = nx; y = ny;
    }
    for (int i = 0; i < n - (size * size); i++) {
        roll.push_back({ x, y++ });
    }
    rollBack = roll;
    sort(rollBack.begin(), rollBack.end(), cmp);
}

void findPoints2()
{
    int cnt = 0;
    int x = 2;

    for (int i = 0; i < 4; i++) {
        if (cnt % 2 == 0) {
            for (int j = n / 4 - 1; j >= 0; j--) {
                fold.push_back({ x, j });
            }
        } else {
            for (int j = 0; j < n / 4; j++) {
                fold.push_back({ x, j });
            }
        }
        if (i != 2) x--;
        else x += 3;
        cnt++;
    }
    foldBack = fold;
    sort(foldBack.begin(), foldBack.end(), cmp);
}

void fly(int flag, vector<pii> points)
{
    if (flag) {
        for (int i = 0; i < n; i++)
            fill_n(air[i], MAX, 0);
    } else {
        sort(points.begin(), points.end(), cmp);
    }

    for (int i = 0; i < n; i++) {
        auto [x, y] = points[i];
        if (flag) // 공중 부양
            air[x][y] = air2[x][y] = fish[i];
        else
            fish[i] = air[x][y];
    }
}

void give(vector<pii> &points)
{
    for (auto [x, y] : points) {
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || air2[nx][ny] == 0)
                continue;

            int diff = (air2[x][y] - air2[nx][ny]) / 5;
            if (diff > 0) {
                air[x][y] -= diff;
                air[nx][ny] += diff;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> fish[i];

    findPoints();
    findPoints2();

    int answer = 0;
    while (true) {
        auto it = minmax_element(fish, fish + n);

        // 최대, 최소의 차가 k 이하면 종료
        if (*it.se - *it.fi <= k)
            break;

        // 물고기 수가 가장 적은 어항에 물고기 한 마리씩 넣는다
        int min = *it.fi;
        for (int i = 0; i < n; i++) {
            if (fish[i] == min)
                fish[i]++;
        }

        // 첫번째 공중 부양 작업
        fly(1, roll);

        // 어항에 있는 물고기 수 조절
        give(roll);

        // 다시 일렬로 놓는다
        fly(0, rollBack);

        // 두번째 공중 부양 작업
        fly(1, fold);

        // 물고기 조절 작업 수행
        give(fold);

        // 다시 일렬로 놓는다
        fly(0, foldBack);

        answer++;
    }
    cout << answer << endl;
    return 0;
}
