#include <iostream>
int main() {
	int h, w, n;
	int** arr, **brr;
	int x, y, l, d;
	
	scanf("%d %d", &h, &w); //����, ����

	//setting
	brr = (int**)malloc(sizeof(int*) * (h+1));
	for (int i = 0; i <= h; i++)
		brr[i] = (int*)malloc(sizeof(int) * (w+1));

	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			brr[i][j] = 0;

	
	scanf("%d", &n); //���� �� �ִ� ������ ��
	arr = (int **)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
		arr[i] = (int*)malloc(sizeof(int) * 4);

	for(int i=0;i<n;i++) //������ ����(0�̸� ����, 1�̸� ����), ����, ��ǥ(x,y)
		scanf("%d %d %d %d", &arr[i][0], &arr[i][1], &arr[i][2], &arr[i][3]);

	for (int k = 0; k < n; k++) {
		x = arr[k][2];
		y = arr[k][3];
		l = arr[k][0];
		d = arr[k][1];
		while (l != 0) {
			brr[x][y] = 1;
			if (d == 0) //������ ���ζ��
				y += 1;
			else
				x += 1;
			l--;
		}
	}

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			printf("%d ", brr[i][j]);
		}
		printf("\n");
	}
}