/*
 * 구현
 * 17413 단어 뒤집기 2
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	getline(cin, s);

	string answer;
	for (int i = 0; i < s.size(); i++) {
		int start = i;
		if (s[i] == '<') {
			while (i + 1 < s.size() && s[i + 1] != '>') {
				i++;
			}
			i++;
			answer += s.substr(start, i - start + 1);
		}
		else if (s[i] == ' ') {
			answer += s[i];
		}
		else {
			while (i + 1 < s.size() && s[i + 1] != '<' && s[i + 1] != '>' && s[i + 1] != ' ') {
				i++;
			}
			string tmp = s.substr(start, i - start + 1);
			reverse(tmp.begin(), tmp.end());
			answer += tmp;
		}
	}
	cout << answer;

	return 0;
}