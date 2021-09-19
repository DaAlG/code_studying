#include <iostream>

using namespace std;

int dx[] = { 1, 0 };
int dy[] = { 0, -1 };

int main()
{
	int T, k;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> k;

		int x = 1;
		int y = 1;
		int tmpy = 0;
		int num = 1;

		while (1) {
			tmpy++;
			int tmp = tmpy * tmpy - 2 * tmpy + 2;
			
			if (tmp > k) break;

			y = tmpy;
			num = tmp;
		}

		int nx = x;
		int ny = y;
		int fx = y;
		int fy = y;
		int dir = 0;
		num--;

		while (num < k) {
			x = nx;
			y = ny;
			num++;

			nx = x + dx[dir];
			ny = y + dy[dir];
			if (nx < 1 || nx > fx || ny < 1 || ny > fy) {
				dir = (dir + 1) % 2;
				nx = x + dx[dir];
				ny = y + dy[dir];
			}
		}
		cout << x << " " << y << "\n";
	}

	return 0;
}