using namespace std;
#include <iostream>
#include <string>
#include <list>

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		list<char> ans;
		string input;
		cin >> input;

		list<char>::iterator idx = ans.end();
		for (int i = 0; i < input.size(); i++) {
			switch (input[i] - '0') {
			case '<'-'0':
				if (idx != ans.begin()) idx--;
				break;
			case '>'-'0':
				if (idx != ans.end()) idx++;
				break;
			case '-'-'0':
				if (idx != ans.begin()) idx = ans.erase(--idx);
				break;
			default:
				ans.insert(idx, input[i]);
			}
		}
		for (auto i = ans.begin(); i != ans.end(); i++)
			cout << *i;
		cout << '\n';
		ans.clear();
	}
	return 0;
}