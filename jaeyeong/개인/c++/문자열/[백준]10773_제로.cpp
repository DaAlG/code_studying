using namespace std;
#include <iostream>
#include <stack>

stack<int> st;
int main() {
	int k, x;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> x;
		if (x == 0) st.pop();
		else st.push(x);
	}
	k = st.size();
	long long answer = 0;
	for (int i = 0; i < k; i++) {
		x = st.top();
		st.pop();
		answer += (long long)x;
	}
	cout << answer << '\n';
}