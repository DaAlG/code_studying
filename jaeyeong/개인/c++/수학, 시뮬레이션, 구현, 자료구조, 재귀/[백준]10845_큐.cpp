using namespace std;
#include <iostream>
#include <queue>
#include <string>

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	queue<int> q;
	int n;
	string s;
	cin >> n;
	while (n--) {
		cin >> s;
		if (s == "push") {
			int x;
			cin >> x;
			q.push(x);
		}
		else if (s == "pop") {
			if (q.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << q.front() << '\n';
			q.pop();
		}
		else if (s == "size") {
			cout << q.size() << '\n';
		}
		else if (s == "empty") {
			cout << q.empty() << '\n';
		}
		else if (s == "front") {
			if (q.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << q.front() << '\n';
		}
		else { //back
			if (q.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << q.back() << '\n';
		}
	}
	return 0;
}