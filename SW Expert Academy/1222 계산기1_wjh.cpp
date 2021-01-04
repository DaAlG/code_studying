// SW Expert Academy
// S/W 문제해결 기본 6일차 - 1222 계산기1

#include <iostream>
#include <string>
#include <stack>

using namespace std;

string postfix(string s)
{
	stack<char> op;
	char exp[200] = "";
	int k = 0;

	for (char ch : s) {
		if (ch == '+') {
			if (op.size() == 0)
				op.push(ch);
			else
				exp[k++] = ch;
		}
		else
			exp[k++] = ch;
	}
	exp[k++] = op.top();
	op.pop();

	return exp;
}

int calc(string s)
{
	stack<int> op;
	for (char ch : s) {
		if (ch == '+') {
			int sum = 0;
			for (int i = 0; i < 2; i++) {
				sum += op.top();
				op.pop();
			}
			op.push(sum);
		}
		else
			op.push(ch - '0');
	}

	return op.top();
}

int main()
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case) {
		int len;
		string exp;
		cin >> len >> exp;

		exp = postfix(exp);
		cout << "#" << test_case << " " << calc(exp) << endl;
	}

	return 0;
}