#include <iostream>

int main() {
    int n, i, j, x, y;
    int a[20][20] = {};
    for (i = 1; i <= 19; i++) //�� �پ� �ٵ��� ��Ȳ �Է� �ޱ�
        for (j = 1; j <= 19; j++)
            scanf("%d", &a[i][j]);

    scanf("%d", &n); //��ǥ ���� �Է¹ޱ�

    for (i = 1; i <= n; i++) //��ǥ�� ������ŭ
    {
        scanf("%d %d", &x, &y);
        for (j = 1; j <= 19; j++) //���� �� ��<->�� �ٲٱ�
        {
            if (a[x][j] == 0) a[x][j] = 1;
            else a[x][j] = 0;
        }
        for (j = 1; j <= 19; j++) //���� �� ��<->�� �ٲٱ�
        {
            if (a[j][y] == 0) a[j][y] = 1;
            else a[j][y] = 0;
        }
    }
    for (i = 1; i <= 19; i++) {
        for (j = 1; j <= 19; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}