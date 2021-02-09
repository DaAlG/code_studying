/*
돌이 3개의 그룹으로 나누어져 있고, 각 그룹에는 돌이 A,B,C개 있다.
돌은 단계별로 움직이고, 각 단계는 다음과 같다
크기가 같지 않은 두 그룹을 고른다. 돌의 개수가 작은 쪽을 X, 큰 쪽을 Y 라고 한다.
X에 있는 돌의 개수를 X+X개로,Y에 있는 돌의 개수를 Y-X로 만든다.
A,B,C가 주어졌을 때, 모든 그룹에 있는 돌의 개수를 같게 만들 수 있는 지 구하는 문제

Y에서 X를 넘겨준다고 보면 됨
DFS, BFS 모두 다 풀 수 있음 : 하나의 시작점이 있을 때 이동할 수 있는지 없는지 볼 수 있는 것과 같음

(A,B,C) : 세 개의 정보 => 정점의 정보
돌의 개수가 매우 커질 수가 있음
1500^3 => 33억 =3기가
공간도 너무 많이 필요하고 시간도 많이 걸림

정점: (A,B,C)로하면 공간이 너무 많이 필요하기 떄문에 (A,B)로 설정하고 해결해도 됨
전체 정점의 개수: A+B+C
A와 B를 알고 있다면 C를 구할 수 있음 => 1500^2
*/
#include <iostream>
#include <queue>
using namespace std;
bool check[1501][1501];
int sum;
void go(int x, int y) { //가능한 구성인지 확인 DFS임
    if (check[x][y]) return;
    check[x][y] = true;
    int a[3] = { x, y, sum - x - y }; // 돌 저장
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i] < a[j]) {
                int b[3] = { x, y, sum - x - y };
                b[i] += a[i];
                b[j] -= a[i];
                go(b[0], b[1]);//가능한지 check
            }
        }
    }
}
int main() {
    int x, y, z;
    cin >> x >> y >> z;
    sum = x + y + z;
    if (sum % 3 != 0) {
        cout << 0 << '\n';
        return 0;// 3으로 나누어 떨어지지 않으면 돌의 개수 똑같아 질 수 없음
    }
    go(x, y); //x,y이용하여 go
    if (check[sum / 3][sum / 3]) {
        cout << 1 << '\n';
    }
    else {
        cout << 0 << '\n';
    }
    return 0;
}