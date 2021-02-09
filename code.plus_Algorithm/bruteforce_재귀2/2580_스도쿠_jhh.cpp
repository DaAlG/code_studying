/*절대로 놓을 수 없는 수는 놓지 않고 지나가는것
백트래킹 브루트포스는 중간에 무언가를 자르면 안됨 모든 방법을 다 만들어 봐야하는데 다만들지 않고 아무리 호출해도 소용 없으면 호출 중단
같은 칸에는 같은 수 있으면 안됨
백트래킹으로 풀수 없는데 이 방식은 가능
*/
#include <iostream>
using namespace std;
int a[10][10];
bool c[10][10];
bool c2[10][10]; //c2[i][j]=i열에 숫자 j가 있으면 true
bool c3[10][10]; //c3[i][j]=i번 작은 정사각형에 숫자 j가 있으면 true
int n = 9;
int square(int x, int y) {
    return (x / 3) * 3 + (y / 3);
}
bool go(int z) { //z 번째 칸을 채우는 함수
    //(x,y) -> 9*x+y번째 칸
   
    if (z == 81) {//마지막칸 호출되면 출력
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
        return true;
    }
    int x = z / n;
    int y = z % n;
    if (a[x][y] != 0) {//이미 수가 있으면 다음 함수 호출
        return go(z + 1);
    }
    else {//아니라면 수를 채워야 함
        for (int i = 1; i <= 9; i++) {
            if (c[x][i] == 0 && c2[y][i] == 0 && c3[square(x, y)][i] == 0) {
                c[x][i] = c2[y][i] = c3[square(x, y)][i] = true;
                a[x][y] = i;
                if (go(z + 1)) {//수채우고 다음거 호출
                    return true;
                }
                a[x][y] = 0;
                c[x][i] = c2[y][i] = c3[square(x, y)][i] = false; 
            }
        }
    }
    return false;
}
int main() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] != 0) {//빈칸이 아니면 미리 전달
                c[i][a[i][j]] = true;
                c2[j][a[i][j]] = true;
                c3[square(i, j)][a[i][j]] = true;
            }
        }
    }
    go(0);
    return 0;
}
