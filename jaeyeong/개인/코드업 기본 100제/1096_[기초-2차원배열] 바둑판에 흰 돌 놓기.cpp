#include <iostream>

int main() {
	int n, i, j, x, y;
	int a[20][20] = {};
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d %d", &x, &y);
		a[x][y] = 1;
	}
	for (i = 1; i <= 19; i++) //�� ��(������ �Ʒ���) ��
	{
		for (j = 1; j <= 19; j++) //�� ��(���ʿ��� ����������) ��
		{
			printf("%d ", a[i][j]); //�� ���
		}
		printf("\n"); //�� �ٲٱ�
	}
}