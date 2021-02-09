/*����� ���� �� ���� ���� ���� �ʰ� �������°�
��Ʈ��ŷ ���Ʈ������ �߰��� ���𰡸� �ڸ��� �ȵ� ��� ����� �� ����� �����ϴµ� �ٸ����� �ʰ� �ƹ��� ȣ���ص� �ҿ� ������ ȣ�� �ߴ�
���� ĭ���� ���� �� ������ �ȵ�
��Ʈ��ŷ���� Ǯ�� ���µ� �� ����� ����
*/
#include <iostream>
using namespace std;
int a[10][10];
bool c[10][10];
bool c2[10][10]; //c2[i][j]=i���� ���� j�� ������ true
bool c3[10][10]; //c3[i][j]=i�� ���� ���簢���� ���� j�� ������ true
int n = 9;
int square(int x, int y) {
    return (x / 3) * 3 + (y / 3);
}
bool go(int z) { //z ��° ĭ�� ä��� �Լ�
    //(x,y) -> 9*x+y��° ĭ
   
    if (z == 81) {//������ĭ ȣ��Ǹ� ���
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
    if (a[x][y] != 0) {//�̹� ���� ������ ���� �Լ� ȣ��
        return go(z + 1);
    }
    else {//�ƴ϶�� ���� ä���� ��
        for (int i = 1; i <= 9; i++) {
            if (c[x][i] == 0 && c2[y][i] == 0 && c3[square(x, y)][i] == 0) {
                c[x][i] = c2[y][i] = c3[square(x, y)][i] = true;
                a[x][y] = i;
                if (go(z + 1)) {//��ä��� ������ ȣ��
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
            if (a[i][j] != 0) {//��ĭ�� �ƴϸ� �̸� ����
                c[i][a[i][j]] = true;
                c2[j][a[i][j]] = true;
                c3[square(i, j)][a[i][j]] = true;
            }
        }
    }
    go(0);
    return 0;
}
