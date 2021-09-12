/*
 * 브루트포스
 * 2231 분해합
 */

#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int answer = 0;
	for (int i = 1; i < n; i++) {
		int result = i;
		int tmp = i;


		while (tmp) {
			result += tmp % 10;
			tmp /= 10;
		}

		if (result == n) {
			answer = i;
			break;
		}
	}

	cout << answer;
	return 0;
}