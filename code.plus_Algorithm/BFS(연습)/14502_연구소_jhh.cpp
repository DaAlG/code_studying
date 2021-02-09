/*
N*M의 직사각형 지도가 있고, 1*1크기의 칸으로 나누어져 있다.
칸: 빈 칸과 벽으로 이루어져 있음
일부 빈 칸에는 바이러스가 있고, 인접한 빈 칸으로 계속해서 퍼져 나간다.
벽을 3개 세워서 바이러스가 퍼질 수 없는 곳의 크기를 구하는 문제

1. 벽을 3개 세움
2. 바이러스가 퍼질 수 없는 곳의 크기 =>BFS, DFS 가능
하나의 정점에서 시작해서 연결된 모든 정점을 방문함

<BFS 와 DFS 의 목적>
한 정점에서 시작해 연결된 모든 정점을 방문하는 것

시간 복잡도 O(NM)

벽을 3개 세우는 경우의 수: (NM)^3
총 (NM)^4시간이 걸림
*/
#include <iostream>
#include <queue>
using namespace std;
int n, m;
int a[10][10];
int b[10][10];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int bfs() {
    queue<pair<int,int>> q;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            b[i][j] = a[i][j];
            if (b[i][j] == 2) { //바이러스의 위치
                q.push(make_pair(i,j));
            }
        }
    }
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (b[nx][ny] == 0) {
                    b[nx][ny] = 2;//바이러스 퍼질 수 있는 칸
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
    int cnt = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (b[i][j] == 0) {//바이러스 퍼지지 않은 칸
                cnt += 1;
            }
        }
    }
    return cnt;
}
int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int x1=0; x1<n; x1++) {
        for (int y1=0; y1<m; y1++) {
            if (a[x1][y1] != 0) continue;
            for (int x2=0; x2<n; x2++) {
                for (int y2=0; y2<m; y2++) {
                    if (a[x2][y2] != 0) continue;
                    for (int x3=0; x3<n; x3++) {
                        for (int y3=0; y3<m; y3++) {
                            if (a[x3][y3] != 0) continue;
                            if (x1 == x2 && y1 == y2) continue;
                            if (x1 == x3 && y1 == y3) continue;
                            if (x2 == x3 && y2 == y3) continue;//3개의 쌍이 같을 수 있으니까 비교
                            a[x1][y1] = 1;
                            a[x2][y2] = 1;
                            a[x3][y3] = 1;
                            int cur = bfs();//BFS돌고 바꿔주기
                            if (ans < cur) ans = cur;
                            a[x1][y1] = 0;
                            a[x2][y2] = 0;
                            a[x3][y3] = 0;
                        }
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
/*
재귀함수를 구현하려면 머리가 복잡해서 for 문으로 많이 구현
코드에다가 3개를 쓰는 경우가 많음
*/