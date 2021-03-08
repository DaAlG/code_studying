#include <iostream>
int main() {
	int h, w, n;
	int** arr, **brr;
	int x, y, l, d;
	
	scanf("%d %d", &h, &w); //세로, 가로

	//setting
	brr = (int**)malloc(sizeof(int*) * (h+1));
	for (int i = 0; i <= h; i++)
		brr[i] = (int*)malloc(sizeof(int) * (w+1));

	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			brr[i][j] = 0;

	
	scanf("%d", &n); //놓을 수 있는 막대의 수
	arr = (int **)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
		arr[i] = (int*)malloc(sizeof(int) * 4);

	for(int i=0;i<n;i++) //막대의 길이(0이면 가로, 1이면 세로), 방향, 좌표(x,y)
		scanf("%d %d %d %d", &arr[i][0], &arr[i][1], &arr[i][2], &arr[i][3]);

	for (int k = 0; k < n; k++) {
		x = arr[k][2];
		y = arr[k][3];
		l = arr[k][0];
		d = arr[k][1];
		while (l != 0) {
			brr[x][y] = 1;
			if (d == 0) //방향이 가로라면
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