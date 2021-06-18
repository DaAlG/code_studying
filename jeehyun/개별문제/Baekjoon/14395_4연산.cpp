/*
 * 그래프
 * 14395 4연산
 */

#include <iostream>
#include <string>
#include <queue>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int s, t;
	cin >> s >> t;

	if (s == t) {
		cout << 0;
		return 0;
	}

	queue<pair<long long, string>> q;
	set<long long> num;
	q.push({s, ""});

	while (!q.empty()) {
		long long now = q.front().first;
		string op = q.front().second;
		q.pop();

		if (now == t) {
			cout << op;
			return 0;
		}

		// *
		if (!num.count(now * now)) {
			num.insert(now * now);
			q.push({ now * now, op + "*" });
		}
	
		// +
		if (!num.count(now + now)) {
			num.insert(now + now);
			q.push({ now + now, op + "+"});
		}

		// -
		if (!num.count(now - now)) {
			num.insert(now - now);
			q.push({ now - now, op + "-" });
		}

		// /
		if (now != 0 && !num.count(now / now)) {
			num.insert(now / now);
			q.push({ now / now, op + "/" });
		}
	}

	cout << -1;
	return 0;
}