/*
 * 자료구조
 * 2504 괄호의 값
 */

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	stack<char> st;
	long long answer = 0;
	int tmp = 1;
	bool impossible = false;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			tmp *= 2;
			st.push('(');
		}
		else if (s[i] == '[') {
			tmp *= 3;
			st.push('[');
		}
		else if (s[i] == ')') {
			// 불가능한 경우
			if (st.empty() || st.top() != '(') {
				impossible = true;
				break;
			}

			if (s[i - 1] == '(')
				answer += tmp;
			st.pop();
			tmp /= 2;
		}
		else if (s[i] == ']') {
			// 불가능한 경우
			if (st.empty() || st.top() != '[') {
				impossible = true;
				break;
			}

			if (s[i - 1] == '[')
				answer += tmp;
			st.pop();
			tmp /= 3;
		}
	}

	if (impossible || !st.empty())
		cout << 0;
	else
		cout << answer;
	
	return 0;
}