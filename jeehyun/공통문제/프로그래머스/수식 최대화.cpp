#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

int getNum(string exp, int &s)
{
	string num;
	for (int i = s; exp[i] >= '0' && exp[i] <= '9'; i++) {
		num += exp[i];
		s = i;
	}
	return stoi(num);
}

long long calc(long long a, long long b, char op)
{
	long long res = 0;

	switch (op) {
	case '*':
		res = a * b;
		break;
	case '+':
		res = a + b;
		break;
	case '-':
		res = a - b;
		break;
	}

	return res;
}

long long getRes(string exp, map<char, int> prior)
{
	stack<long long> sn; // operand
	stack<char> sop; // oprator

	char ch;
	for (int i = 0; i < exp.size(); i++) {
		ch = exp[i];

		if (ch >= '0' && ch <= '9')
			sn.push(getNum(exp, i));

		if (ch == '*' || ch == '+' || ch == '-') {
			if (sop.empty())
				sop.push(ch);
			else {
				// 스택에 우선순위가 높거나 같은 연산자가 있을경우 계산해준다
				while (!sop.empty() && prior[ch] <= prior[sop.top()]) {
					char op = sop.top(); sop.pop();
					long long b = sn.top(); sn.pop();
					long long a = sn.top(); sn.pop();
					sn.push(calc(a, b, op));
				}
				sop.push(ch);
			}
		}
	}

	// 남은 연산
	while (!sop.empty()) {
		char op = sop.top(); sop.pop();
		long long b = sn.top(); sn.pop();
		long long a = sn.top(); sn.pop();
		sn.push(calc(a, b, op));
	}

	return sn.top();
}

long long solution(string expression) 
{
	long long answer = 0;
	char op[3] = { '*', '+', '-' };
	map<char, int> prior;
	vector<int> perm;

	// *, +, - 연산자 있는지 확인
	for (int i = 0, j = 0; i < 3; i++) {
		if (find(op, op + 3, op[i]) != op + 3) {
			prior[op[i]] = j;
			perm.push_back(j++);
		}
	}

	do {
		// 연산자 우선순위를 정한다
		for (int i = 0, j = 0; i < 3, j < perm.size(); i++) {
			if (prior.find(op[i]) != prior.end())
				prior[op[i]] = perm[j++];
		}
		answer = max(answer, abs(getRes(expression, prior)));
	} while (next_permutation(perm.begin(), perm.end()));

	return answer;
}

int main()
{
	string expression = "2-990-5+2+3*2";
	cout << solution(expression);
	return 0;
}