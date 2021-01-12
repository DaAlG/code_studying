// SW Expert Academy
// S/W 문제해결 기본 8일차 - 1230 암호문3

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

		vector<int> pw(5000);
		for (int i = 0; i < len; i++) {
			cin >> pw[i];
		}

		cin >> len;
		for (int i = 0; i < len; i++) {
			char cmd;
			int pos, n;
			cin >> cmd;

			if (cmd == 'I') {
				cin >> pos >> n;
				for (int k = 0; k < n; k++) {
					int num;
					cin >> num;
					pw.insert(pw.begin() + pos + k, num);
				}
			}
			else if (cmd == 'A') {
				cin >> n;
				for (int k = 0; k < n; k++) {
					int num;
					cin >> num;
					pw.push_back(num);
				}
			}
			else {
				cin >> pos >> n;
				pw.erase(pw.begin() + pos, pw.begin() + pos + n);
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