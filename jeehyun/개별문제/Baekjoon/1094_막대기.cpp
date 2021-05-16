/*
 * 비트마스킹
 * 1094 막대기
 */

#include <iostream>

using namespace std;

int stick[65];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x;
	cin >> x;

	if (x == 64) {
		cout << 1;
		return 0;
	}

	int s = 1 << 6;
	int length = 64;
	int shortest = length;
	stick[64] = 1;

	while (length > x) {
		int half = shortest / 2;
		stick[shortest]--;
		stick[half]++;

		if (stick[shortest] == 0)
			s &= ~(shortest);
		s |= half;

		int sum = 0;
		int cnt = 0;
		for (int i = half; i <= (1 << 6); i++) {
			if ((s & i) == i) {
				sum += i * stick[i];
				cnt += stick[i];
			}
		}

		if (sum == x) {
			cout << cnt;
			return 0;
		}
		else if (sum < x) {
			sum += half;
			stick[half]++;
		}

		length = sum;
		shortest = half;
	}

	return 0;
}