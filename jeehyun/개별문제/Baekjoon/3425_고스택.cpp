/*
 * 자료구조
 * 3425 고스택
 */

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#define MAX 1000000000
using namespace std;

stack<int> st;

bool execute(string s)
{
	string cmd = s.substr(0, 3);

	if (cmd == "NUM") {
		st.push(stoi(s.substr(4)));
	}
	else if (cmd == "POP") {
		if (st.empty())
			return false;
		st.pop();
	}
	else if (cmd == "INV") {
		if (st.empty())
			return false;
		st.top() *= -1;
	}
	else if (cmd == "DUP") {
		if (st.empty())
			return false;
		st.push(st.top());
	}
	else {
		if (st.size() < 2)
			return false;

		long long tmp = st.top(); st.pop();
		long long tmp2 = st.top(); st.pop();

		if (cmd == "SWP") {
			st.push(tmp);
			st.push(tmp2);
		}
		else if (cmd == "ADD") {
			if (abs(tmp + tmp2) > MAX)
				return false;
			st.push(tmp + tmp2);
		}
		else if (cmd == "SUB") {
			if (abs(tmp2 - tmp) > MAX)
				return false;
			st.push(tmp2 - tmp);
		}
		else if (cmd == "MUL") {
			if (abs(tmp * tmp2) > MAX)
				return false;
			st.push(tmp * tmp2);
		}
		else { // DIV, MOD
			if (tmp == 0)
				return false;

			if (cmd == "DIV") {
				int sign = ((tmp >= 0 && tmp2 >= 0) || (tmp < 0 && tmp2 < 0)) ? 1 : -1;
				st.push((abs(tmp2) / abs(tmp)) * sign);
			}
			else { // MOD
				int sign = tmp2 >= 0 ? 1 : -1;
				st.push((abs(tmp2) % abs(tmp)) * sign);
			}
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> cmd;
	string s;

	while (getline(cin, s)) {
		if (s == "QUIT")
			break;
		else if (s == "END") {
			int n, k;
			cin >> n;

			for (int i = 0; i < n; i++) {
				cin >> k;
				st.push(k);

				bool error = false;
				for (int j = 0; j < cmd.size(); j++) {
					if (!execute(cmd[j])) {
						error = true;
						break;
					}
				}

				if (st.size() != 1 || error)
					cout << "ERROR\n";
				else
					cout << st.top() << '\n';

				while (!st.empty()) {
					st.pop();
				}
			}
			cout << '\n';
			cmd.clear();
		}
		else if (!s.empty()) {
			cmd.push_back(s);
		}
	}
	return 0;
}