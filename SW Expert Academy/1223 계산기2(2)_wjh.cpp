// SW Expert Academy
// S/W 문제해결 기본 6일차 - 1223 계산기2

#include <iostream>

using namespace std;

int main()
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case) {
		int len;
		cin >> len;

		int num, ans = 0;
		for (int i = 0; i < len; i++) {
			char ch;
			cin >> ch;
			if (ch == '+') {
				ans += num;
			}
			else if (ch == '*') {
				cin >> ch;
				i++;
				num *= ch - '0';
			}
			else
				num = ch - '0';
		}
		ans += num;

		cout << "#" << test_case << " " << ans << endl;
	}

	return 0;
}