#include <vector>
#include <queue>
#include <string.h>
#define MAX 100
using namespace std;

int height, width;
bool visit[MAX][MAX] = { false };
int direction[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

bool inRange(int x, int y) {
    return 0 <= x && x < height && 0 <= y && y < width;
}

int bfs(vector<vector<int>> picture, int sx, int sy) {
    int size = 0;
    queue<pair<int, int>> q;
    visit[sx][sy] = true;
    q.push(make_pair(sx, sy));
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        int c = picture[x][y];
        size++;
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + direction[d][0];
            int ny = y + direction[d][1];
            if (!inRange(nx, ny) || visit[nx][ny] || picture[nx][ny]!=c) continue;
            visit[nx][ny] = true;
            q.push(make_pair(nx, ny));
        }
    }
    return size;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    memset(visit, false, sizeof(visit));
    height = m;
    width = n;
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] != 0 && !visit[i][j]) {
                max_size_of_one_area = max(bfs(picture, i, j), max_size_of_one_area);
                number_of_area++;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}