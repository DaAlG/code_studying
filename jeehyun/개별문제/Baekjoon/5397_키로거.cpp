/*
 * 자료구조
 * 5397 키로거
 */

#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		string s;
		cin >> s;

		list<char> answer;
		auto cur = answer.end();

		for (char ch : s) {
			if (ch == '<') {
				if (cur != answer.begin()) 
					cur--;
			}
			else if (ch == '>') {
				if (cur != answer.end()) 
					cur++;
			}
			else if (ch == '-') {
				if (cur != answer.begin())
					answer.erase(prev(cur));
			}
			else {
				answer.insert(cur, ch);
			}
		}

		for (char ch : answer) {
			cout << ch;
		}
		cout << '\n';
	}

	return 0;
}