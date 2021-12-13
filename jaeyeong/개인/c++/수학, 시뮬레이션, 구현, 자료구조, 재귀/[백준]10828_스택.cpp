using namespace std;
#include <iostream>
#include <stack>

int main() {
	stack<int> st;
	int n;
	cin >> n;
	while (n--) {
		string o;
		int k;
		cin >> o;
		if (o == "push") {
			cin >> k;
			st.push(k);
		}
		else if (o == "pop") {
			if (st.empty())
				cout << "-1\n";
			else {
				cout << st.top() << '\n';
				st.pop();
			}
		}
		else if (o == "size") {
			cout << st.size() << '\n';
		}
		else if (o == "empty") {
			if (st.empty()) cout << "1\n";
			else cout << "0\n";
		}
		else if (o == "top") {
			if (st.empty())
				cout << "-1\n";
			else
				cout << st.top() << '\n';
		}
	}
}