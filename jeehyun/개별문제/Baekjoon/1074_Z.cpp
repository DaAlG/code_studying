/*
 * 분할 정복
 * 1074 Z
 */

#include <iostream>
using namespace std;

int n, r, c;
int answer = 0;

void go(int x, int y, int size)
{
	if (x == r && y == c) {
		cout << answer;
		return;
	}

	// r, c가 현재 사분면에 존재한다면
	if (r >= x && r < x + size && c >= y && c < y + size) {
		// 1사분면 탐색
		go(x, y, size / 2);

		// 2사분면 탐색
		go(x, y + size / 2, size / 2);

		// 3사분면 탐색
		go(x + size / 2, y, size / 2);

		// 4사분면 탐색
		go(x + size / 2, y + size / 2, size / 2);
	}
	else {
		// r, c가 현재 사분면에 존재하지 않는다면 현재 사분면의 크키를 더해준다
		answer += size * size;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> r >> c;
	go(0, 0, (1 << n));

	return 0;
}