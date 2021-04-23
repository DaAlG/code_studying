/*
 * 자료구조
 * 1935 후위 표기식2
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int v[26];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	string exp;
	cin >> exp;
	
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	stack<double> st;
	for (char ch : exp) {
		if (ch >= 'A' && ch <= 'Z') {
			st.push(v[ch - 'A']);
		}
		else {
			double b = st.top(); st.pop();
			double a = st.top(); st.pop();

			if (ch == '*') {
				st.push(a * b);
			}
			else if (ch == '/') {
				st.push(a / b);
			}
			else if (ch == '+') {
				st.push(a + b);
			}
			else { // -
				st.push(a - b);
			}
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << st.top();
	return 0;
}