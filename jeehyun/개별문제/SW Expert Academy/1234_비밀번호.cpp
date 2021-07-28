#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

stack<char> st;

int main(int argc, char** argv)
{
	int T = 10;
	for (int test_case = 1; test_case <= T; ++test_case) {
		int len; string pw;
		cin >> len >> pw;

		for (char num : pw) {
			if (!st.empty() && st.top() == num) {
				while (!st.empty() && st.top() == num) {
					st.pop();
				}
			}
			else {
				st.push(num);
			}
		}

		string answer;
		while (!st.empty()) {
			answer += st.top();
			st.pop();
		}
		reverse(answer.begin(), answer.end());
		cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;
}