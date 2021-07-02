/*
 * 자료구조
 * 9935 문자열 폭발
 */

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s, bomb;
	cin >> s >> bomb;

	stack<char> st;
	int len = bomb.size();

	for (int i = 0; i < s.size(); i++) {
		st.push(s[i]);
		if (s[i] == bomb.back()) {
			bool exploded = true;
			string tmp;

			// 폭발 문자열인지 확인
			for (int j = len - 1; j >= 0; j--) {
				if (st.empty() || st.top() != bomb[j]) {
					exploded = false;
					break;
				}
				tmp += st.top();
				st.pop();
			}

			// 폭발 문자열이 아니면 다시 스택에 넣는다
			if (!exploded) {
				while (!tmp.empty()) {
					st.push(tmp.back());
					tmp.pop_back();
				}
			}
		}
	}

	if (st.empty())
		cout << "FRULA";
	else {
		string answer;
		while (!st.empty()) {
			answer += st.top();
			st.pop();
		}
		reverse(answer.begin(), answer.end());
		cout << answer;
	}

	return 0;
}