/*
 * 문자열
 * 9093 단어 뒤집기
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	cin.ignore();

	while (T--) {
		string s, tmp, answer;
		getline(cin, s);

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ' || i == s.size() - 1) {
				if (i == s.size() - 1)
					tmp += s[i];
				reverse(tmp.begin(), tmp.end());
				answer += tmp + ' ';
				tmp.clear();
			}
			else {
				tmp += s[i];
			}
		}
		cout << answer << '\n';
	}
	return 0;
}