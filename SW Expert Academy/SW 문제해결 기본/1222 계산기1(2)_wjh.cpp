// SW Expert Academy
// S/W 문제해결 기본 6일차 - 1222 계산기1

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case) {
		int len;
		string exp;
		cin >> len >> exp;

		int ans = 0;
		for (char ch : exp) {
			if (ch != '+') {
				ans += ch - '0';
			}
		}
		cout << "#" << test_case << " " << ans<< endl;
	}

	return 0;
}