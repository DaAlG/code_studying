#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
int const dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

struct Point {
    int d, y, x;
    Point(int y, int x) :y(y), x(x) {}
    Point(int d, int y, int x) :d(d), y(y), x(x) {}
};

// �켱���� ť �� ������ �������̵�
bool operator < (Point a, Point b) {
    return a.d > b.d;
}

bool done(vector<vector<int>>& board) {
    for (auto v : board) for (int i : v) if (i != 0) return false;
    return true;
}

bool inRange(int y, int x) {
    if ((0 <= y && y < 4) && (0 <= x && x < 4)) return true;
    return false;
}
//���ͽ�Ʈ�� �̿��� �ּ� Ű���� Ƚ�� ��ȯ
int getDist(vector<vector<int>>& board, int y1, int x1, int y2, int x2) {
    priority_queue<Point> q;
    q.push(Point(0, y1, x1));

    int dist[4][4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            dist[i][j] = 1e9;
    dist[y1][x1] = 0;

    while (!q.empty()) {
        Point cur = q.top();
        q.pop();

        int curDist = cur.d;

        if (dist[cur.y][cur.x] < cur.d) continue;
        if (cur.y == y2 && cur.x == x2) return curDist;

        for (int i = 0; i < 4; i++) {
            int cnt = 0;
            int ny = cur.y, nx = cur.x;
            // �� ĭ�� i�������� �Űܰ��� �ִܰŸ� ���
            while (inRange(ny + dir[i][1], nx + dir[i][0])) {
                cnt++;
                ny += dir[i][1]; nx += dir[i][0];

                if (board[ny][nx] != 0) break; // ī�� ����ħ

                if (dist[ny][nx] > curDist + cnt) {
                    dist[ny][nx] = curDist + cnt;
                    q.push(Point(curDist + cnt, ny, nx));
                }
            }
            // ī�� �Ǵ� ���� ����ģ ��� Ctrl Ű�� �̿��� 1������ �̵� ����
            if (dist[ny][nx] > curDist + 1) {
                dist[ny][nx] = curDist + 1;
                q.push(Point(curDist + 1, ny, nx));
            }
        }
    }
}
int solve(vector<vector<int>>& board, int y, int x) {
    if (done(board)) return 0; //���� ������
    int ret = 0x3f3f3f3f;

    //ī�� k ������
    for (int k = 1; k <= 6; k++) {
        vector<Point> point;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (board[i][j] == k)
                    point.push_back(Point(i, j));

        if (point.empty()) continue;
        
        int cand1 = getDist(board, y, x, point[0].y, point[0].x)
            + getDist(board, point[0].y, point[0].x, point[1].y, point[1].x) + 2;

        int cand2 = getDist(board, y, x, point[1].y, point[1].x)
            + getDist(board, point[1].y, point[1].x, point[0].y, point[0].x) + 2;

        //dfs
        board[point[0].y][point[0].x] = 0;
        board[point[1].y][point[1].x] = 0;

        ret = min(ret, min(cand1 + solve(board, point[1].y, point[1].x),
            cand2 + solve(board, point[0].y, point[0].x)));

        //��Ʈ��ŷ�̴ϱ�
		board[point[0].y][point[0].x]=k;
		board[point[1].y][point[1].x]=k;
    }
    return ret;
}


int solution(vector<vector<int>> board, int r, int c) {
    int answer = solve(board, r, c);
    return answer;
}

int main() {
    vector<vector<int>> board = { {1,0,0,3} ,{2,0,0,0},{0,0,0,2},{3,0,1,0} };
    int r = 1, c = 0;
    cout << solution(board, r, c);
}