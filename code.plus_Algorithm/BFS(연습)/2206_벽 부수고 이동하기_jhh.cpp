/*
N*M의 행렬로 나타내는 지도에서 (1,1)에서 (N,M)으로 최단거리로 이동하는 문제
0은 빈칸, 1은 벽

단, 벽은 한번 부수고 지나갈 수 있다 => 중요

bfs에서 가장 중요한 것: 정점의 정의
보통은 정형화되어 있음
하나의 칸에서 다른 인접한 네개의 칸으로 이동

빈칸 -> 빈칸 : 항상 가능
빈칸 -> 벽 : 항상 가능한 것이 아님
    -벽을 한번 부순적이 없을 때 이동가능
    - 아니면 이동 불가능
하나의 정점이 할 수 있는 행동이 다른 요인에 의해서 바뀌었을 때 -> 이걸 기준으로 나눠줌
행과 열의 좌표가 아니고 벽을 부순 횟수인 k가 필요하게 됨 (r,c,k)
    (r,c,0) => 가능
    (r,c,1) => 불가능, 빈칸으로만 갈 수 있음
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstdio>
#include <tuple>
using namespace std;
int a[1000][1000];
int d[1000][1000][2];//0,1 정보
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main() {
    int n, m;
    scanf("%d %d",&n,&m);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%1d",&a[i][j]);
        }
    }
    queue<tuple<int,int,int>> q;
    d[0][0][0] = 1;
    q.push(make_tuple(0,0,0));
    while (!q.empty()) {
        int x, y, z; //z: 벽을 부수는 횟수
        tie(x,y,z) = q.front(); q.pop(); // 벽 부수는 횟수
        for (int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (a[nx][ny] == 0 && d[nx][ny][z] == 0) {// 빈칸인 경우
                d[nx][ny][z] = d[x][y][z] + 1;
                q.push(make_tuple(nx,ny,z));
            }
            if (z == 0 && a[nx][ny] == 1 && d[nx][ny][z+1] == 0) {//벽인 경우
                // z==0: 한번도 안부쉈을 경우
                d[nx][ny][z+1] = d[x][y][z] + 1;
                q.push(make_tuple(nx,ny,z+1));
            }
        }
    }
    if (d[n-1][m-1][0] != 0 && d[n-1][m-1][1] != 0) {
        cout << min(d[n-1][m-1][0], d[n-1][m-1][1]);
    } else if (d[n-1][m-1][0] != 0) {
        cout << d[n-1][m-1][0];
    } else if (d[n-1][m-1][1] != 0) {
        cout << d[n-1][m-1][1];
    } else {
        cout << -1;
    }
    cout << '\n';
    return 0;
}
