/*
 * 문자열
 * 2941 크로아티아 알파벳
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	int answer = 1;
	for (int i = 1; i < s.size(); i++) {
		answer++;
		if (s[i] == '=') {
			if (s[i - 1] == 'c' || s[i - 1] == 's' || s[i - 1] == 'z') {
				if (i >= 2 && s[i - 1] == 'z' && s[i - 2] == 'd')
					answer -= 2;
				else
					answer--;
			}
		}
		else if (s[i] == 'j') {
			if (s[i - 1] == 'l' || s[i - 1] == 'n')
				answer--;
		}
		else if (s[i] == '-') {
			if (s[i - 1] == 'c' || s[i - 1] == 'd')
				answer--;
		}
	}
	cout << answer;
	return 0;
}