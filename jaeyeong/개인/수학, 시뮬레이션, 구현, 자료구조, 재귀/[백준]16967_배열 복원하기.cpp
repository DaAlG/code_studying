using namespace std;
#include <iostream>

int h, w, x, y;
int arr[1000][1000], brr[1000][1000];
int points[2][2];
int main() {
	cin >> h >> w >> x >> y;
	int k;
	int mx, my;
	for (int i = 0; i < (h + x); i++) {
		for (int j = 0; j < (w + y); j++) {
			cin >> brr[i][j];
			if (0 <= i && i < x && 0 <= j && j < w)
				arr[i][j] = brr[i][j];
			if (x <= i && i < h && 0 <= j && j < y)
				arr[i][j] = brr[i][j];
			if (x <= i && i < h && y <= j && j < w)
				arr[i][j] = brr[i][j] - arr[i - x][j - y];
			if (h <= i && i < h + x && y <= j && j < w + y)
				arr[i-x][j-y] = brr[i][j];
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}