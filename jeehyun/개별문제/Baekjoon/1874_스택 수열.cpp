/*
 * 자료구조
 * 1874 스택 수열
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int arr[100000];
int idx[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		idx[arr[i]] = i;
	}

	stack<int> st;
	vector<char> answer;
	vector<int> res;

	for (int i = 1; i <= n; i++) {
		while (!st.empty() && idx[st.top()] < idx[i]) {
			res.push_back(st.top());
			st.pop();
			answer.push_back('-');
		}

		st.push(i);
		answer.push_back('+');
	}

	while (!st.empty()) {
		res.push_back(st.top());
		answer.push_back('-');
		st.pop();
	}

	bool possible = true;
	for (int i = 0; i < n; i++) {
		if (arr[i] != res[i]) {
			possible = false;
			break;
		}
	}

	if (possible) {
		for (char ch : answer) {
			cout << ch << '\n';
		}
	}
	else
		cout << "NO\n";

	return 0;
}