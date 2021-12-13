using namespace std;
#include <iostream>
#include <string>
#include <stack>

int main() {
	string s;
	getline(cin, s);
	while (s != ".") {
		stack<int> big, small;
		int size = s.size();
		bool flag = true;
		for (int i = 0; i < size; i++) {
			if (flag == false) break;
			if (s[i] == '[') big.push(i);
			else if (s[i] == '(') small.push(i);
			else if (s[i] == ']') {
				if (big.empty() || (!small.empty() && big.top() < small.top())) {
					flag = false;
					continue;
				}
				big.pop();
			}
			else if (s[i] == ')') {
				if (small.empty() || (!big.empty() && small.top() < big.top())) {
					flag = false;
					continue;
				}
				small.pop();
			}
		}
		if (!small.empty() || !big.empty()) flag = false;
		string answer = flag == true ? "yes" : "no";
		cout << answer << '\n';
		getline(cin, s);
	}
}