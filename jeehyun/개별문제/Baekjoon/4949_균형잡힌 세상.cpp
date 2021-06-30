/*
 * 자료구조
 * 4949 균형잡힌 세상
 */

#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;

	map<char, char> mp;
	mp[')'] = '(';
	mp[']'] = '[';

	while (getline(cin, s)) {
		if (s == ".")
			break;

		stack<char> st;
		bool impossible = false;

		for (char ch : s) {
			if (ch == '(' || ch == '[') {
				st.push(ch);
			}
			else if (ch == ')' || ch == ']') {
				if (st.empty() || st.top() != mp[ch]) {
					impossible = true;
					break;
				}
				st.pop();
			}
		}

		if (!st.empty() || impossible) cout << "no\n";
		else cout << "yes\n";
	}

	return 0;
}