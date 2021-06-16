using namespace std;
#include <iostream>
#include <stack>
int main() {
	string s;
	int tc;
	cin >> tc;
	while (tc--) {
		stack<char> st;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') st.push('(');
			else if (s[i] == ')') {
				if (st.empty()) {
					cout << "NO\n";
					break;
				}
				else st.pop();
			}
			if (i == s.size() - 1) {
				if(st.empty()) cout << "YES\n";
				else cout << "NO\n";
			}
		}
	}
}