/* 
 * 자료구조
 * 1918 후위 표기식
 */

#include <iostream>
#include <stack>
#include <map>
using namespace std;

map<char, int> prior;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string exp;
	cin >> exp;

	string post;
	stack<char> st;

	prior['('] = prior[')'] = 0;
	prior['+'] = prior['-'] = 1;
	prior['*'] = prior['/'] = 2;

	for (int i = 0; i < exp.size(); i++) {
		if (exp[i] >= 'A' && exp[i] <= 'Z')
			post += exp[i];
		else if (exp[i] == '(') {
			st.push(exp[i]);
		}
		else if (exp[i] == ')') {
			while (!st.empty() && st.top() != '(') {
				post += st.top();
				st.pop();
			}
			st.pop();
		}
		else if (exp[i] == '*' || exp[i] == '/') {
			while (!st.empty() && prior[exp[i]] <= prior[st.top()]) {
				post += st.top();
				st.pop();
			}
			st.push(exp[i]);
		}
		else if (exp[i] == '+' || exp[i] == '-') {
			while (!st.empty() && prior[exp[i]] <= prior[st.top()]) {
				post += st.top();
				st.pop();
			}
			st.push(exp[i]);
		}
	}

	while (!st.empty()) {
		post += st.top();
		st.pop();
	}
	cout << post;

	return 0;
}