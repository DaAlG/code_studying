using namespace std;
#include <iostream>
#include <queue>
#define MAX 100


int main() {
	int tc, n;
	int x, y;
	cin >> tc;
	while (tc--) {
		cin >> n;
		priority_queue<int> strs;
		for (int i = 0; i < n; i++) {
			cin >> x;
			strs.push(-x);
		}
		int ans = 0;
		while (strs.size()!=1) {
			x = -strs.top();
			strs.pop();
			y = -strs.top();
			strs.pop();
			strs.push(-x - y);
			ans += (x + y);
		}
		cout << ans << '\n';
	}
}