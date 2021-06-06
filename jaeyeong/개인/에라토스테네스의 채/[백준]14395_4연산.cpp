using namespace std;
#include <iostream>
#include <queue>
#include <set>

long long s, t;
set<long long> st;

void bfs() {
	bool flag = false;
	queue<pair<long long, string>> q;
	q.push(make_pair(s,""));
	st.insert(s);
	while (!q.empty()) {
		long long c = q.front().first;
		string cs = q.front().second;
		q.pop();
		if (c == t) {
			flag = true;
			cout << cs << '\n';
			break;
		}
		// *
		for (int i = 0; i < 4; i++) {
			long long next;
			char ns;
			switch (i) {
			case 0: next = c * c; ns = '*';  break;
			case 1: next = c + c; ns = '+';  break;
			case 2: next = c - c; ns = '-';  break;
			case 3: if (c != 0) next = c / c; ns = '/';  break;
			}
			if (i == 3 && c == 0) continue;
			if (0 < next && st.find(next) == st.end()) {
				st.insert(next);
				q.push(make_pair(next, cs + ns));
			}
		}
	}
	if (flag == false) cout << "-1\n";
}
int main() {
	cin >> s >> t;
	if (s == t) cout << "0\n";
	else bfs();
}