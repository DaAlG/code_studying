// SW Expert Academy
// S/W 문제해결 기본 3일차 - 1213 String

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> test_case;

		string str, ptn;
		cin >> ptn >> str;

		int index, ans = 0;
		for (int k = 0; k < str.size();) {
			index = str.find(ptn, k);

			if (index == string::npos)
				break;
			else {
				ans++; k = ++index;
			}
		}
		

		cout << "#" << test_case << " " << ans << endl;
	}

	return 0;
}