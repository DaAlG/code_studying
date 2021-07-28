#include <iostream>
#include <stack>
using namespace std;

stack<int> num;
stack<char> ops;

int calc() {
	char op = ops.top(); ops.pop();
	int a = num.top(); num.pop();
	int b = num.top(); num.pop();
	if (op == '*') return a * b;
	else return a + b;
}

int main(int argc, char** argv)
{
	int T = 10;
	for (int test_case = 1; test_case <= T; ++test_case) {
		int len; string exp;
		cin >> len >> exp;

		for (char ch : exp) {
			if (ch >= '0' && ch <= '9')
				num.push(ch - '0');
			else if (ch == ')') {
				// 괄호 안의 연산을 모두 해준다
				while (!ops.empty() && ops.top() != '(') {
					num.push(calc());
				}
				ops.pop();
			}
			else if (ch == '+'&& !ops.empty() && ops.top() == '*') {
				// 덧셈보다 우선순위가 높은 곱셈을 모두 계산한다
				while (!ops.empty() && ops.top() == '*') {
					num.push(calc());
				}
				ops.push(ch);
			}
			else
				ops.push(ch);
		}

		// 남은 연산을 해준다
		while (!ops.empty()) {
			num.push(calc());
		}

		cout << "#" << test_case << " " << num.top() << "\n";
		num.pop();
	}
	return 0;
}