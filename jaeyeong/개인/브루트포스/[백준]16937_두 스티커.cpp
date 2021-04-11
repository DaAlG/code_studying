using namespace std;
#include <iostream>

int sticker[101][2];
int h, w, n;
int arr[3], visit[3];
int ans;

//현재 arr에 담긴 값으로 차지할 수 있는 최대 면적
void possibleArea() {
	int ax = sticker[arr[1]][0], ay = sticker[arr[1]][1];
	int bx = sticker[arr[2]][0], by = sticker[arr[2]][1];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (i == 1 && j==0)
				swap(ax, ay);
			if (j == 1)
				swap(bx, by);

			int x = ax + bx;
			int y = max(ay, by);
			if (x <= h && y <= w)
				ans = max(ax * ay + bx * by, ans);

			x = max(ax, bx);
			y = ay + by;
			if (x <= h && y <= w)
				ans = max(ax * ay + bx * by, ans);
		}
	}
}

int main() {
	cin >> h >> w >> n;
	for (int i = 1; i <= n; i++)
		cin >> sticker[i][0] >> sticker[i][1];

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			arr[1] = i;
			arr[2] = j;
			possibleArea();
		}
	}
	cout << ans << '\n';
}
