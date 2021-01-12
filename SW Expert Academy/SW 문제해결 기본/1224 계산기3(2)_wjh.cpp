// SW Expert Academy
// S/W 문제해결 기본 6일차 - 1224 계산기3

#include <iostream>

using namespace std;

int calc(string s, int &len)
{
	int res = 0;
	int num;
	char op = '\0';

	for (int i = len; i < s.length(); i++) {
		switch (s[i]) {
		case '(':
			len = i + 1;
			if (op == '*')
				num *= calc(s, len);
			else
				num = calc(s, len);
			i = len;
			break;
		case '*':
			if (s[i + 1] != '(')
				num *= s[++i] - '0';
			else
				op = '*';
			break;
		case '+':
			res += num;
			if (s[i + 1] == '(')
				op = '+';
			break;
		case ')':
			len = i;
			res += num;
			return res;
		default:
			num = s[i] - '0';
		}

	}

	return res;
}

int main()
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case) {
		int len;
		string exp;
		cin >> len >> exp;

		len = 1;
		cout << "#" << test_case << " " << calc(exp, len) << endl;
	}

	return 0;
}