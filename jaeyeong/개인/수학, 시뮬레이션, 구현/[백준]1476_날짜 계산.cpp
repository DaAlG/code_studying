using namespace std;
#include <iostream>

int e, s, m;

int solution() {
	int ce=1, cs=1, cm=1;
	int ans = 1;
	while (ce != e || cs != s || cm != m) {
		ce++;
		cs++;
		cm++;
		ans++;
		if (ce > 15) ce = 1;
		if (cs > 28) cs = 1;
		if (cm > 19) cm = 1;
	}
	return ans;
}
int main() {
	cin >> e >> s >> m;
	cout << solution() << '\n';
}