// SW Expert Academy
// S/W 문제해결 기본 8일차 - 1228 암호문1

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case) {
		int len;
		cin >> len;

		vector<int> pw(200);
		for (int i = 0; i < len; i++) {
			cin >> pw[i];
		}

		cin >> len;
		for (int i = 0; i < len; i++) {
			char cmd;
			int pos, n;
			cin >> cmd >> pos >> n;

			int num;
			for (int k = 0; k < n; k++) {
				cin >> num;
				pw.insert(pw.begin() + pos + k, num);
			}
		}

		cout << "#" << test_case << " ";
		for (int i = 0; i < 10; i++) {
			cout << pw[i] << " ";
		}
		cout << endl;
	}

	return 0;
}