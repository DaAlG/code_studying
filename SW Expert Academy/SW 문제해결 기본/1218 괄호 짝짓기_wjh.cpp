// SW Expert Academy
// S/W 문제해결 기본 4일차 - 1218 괄호 짝짓기

#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case) {
		int n;
		cin >> n;

		stack<char> s;
		string txt;
		cin >> txt;

		int ans = 1;
		for (char ch : txt) {
			if (ch == '(' || ch == '[' || ch == '{' || ch == '<')
				s.push(ch);
			else {
				char p = s.top();

				if ((p == '(' && ch == ')') || (p == '[' && ch == ']') || (p == '{' && ch == '}') || (p == '<' && ch == '>'))
					s.pop();
				else {
					ans = 0;
					break;
				}
			}
		}

		cout << "#" << test_case << " " << ans << endl;
	}

	return 0;
}