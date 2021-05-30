using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

vector<string> input;
int tc, n;

void solve() {
	string comp;
	for (int i = 0; i < (n-1); i++) {
		int current = input[i].length();
		int next = input[i + 1].length();
		if (current < next) {
			if (input[i + 1].substr(0, current) == input[i]) {
				cout << "NO\n";
				return;
			}
		}
	}
	cout << "YES\n";
	return;
}
int main() {
	string s;
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> s;
			input.push_back(s);
		}
		sort(input.begin(), input.end());
		solve();
		input.clear();
	}
}