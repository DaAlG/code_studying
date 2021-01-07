// SW Expert Academy
// S/W 문제해결 기본 6일차 - 1224 계산기3

#include <iostream>
#include <stack>

using namespace std;

string postfix(string s)
{
	stack<char> op;
	char exp[200] = "";
	int k = 0;

	for (char ch : s) {
		switch (ch) {
		case '(':
			op.push(ch);
			break;
		case '*':
			if (op.top() == '*')
				exp[k++] = ch;
			else
				op.push(ch);
			break;
		case '+':
			if (op.top() == '*') {
				while (op.top() == '*') {
					exp[k++] = op.top();
					op.pop();
				}

				if (op.top() != '(')
					exp[k++] = ch;
				else
					op.push(ch);
			}
			else if (op.top() == '+')
				exp[k++] = ch;
			else
				op.push(ch);
			break;
		case ')':
			while (op.top() != '(') {
				exp[k++] = op.top();
				op.pop();
			}
			op.pop();
			break;
		default:
			exp[k++] = ch;
		}
	}

	return exp;
}

int calc(string s)
{
	stack<int> op;
	for (char ch : s) {
		switch (ch) {
		case '*': {
			int mult = 1;
			for (int i = 0; i < 2; i++) {
				mult *= op.top();
				op.pop();
			}
			op.push(mult);
			break;
		}
		case '+': {
			int sum = 0;
			for (int i = 0; i < 2; i++) {
				sum += op.top();
				op.pop();
			}
			op.push(sum);
			break;
		}
		default:
			op.push(ch - '0');
		}
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