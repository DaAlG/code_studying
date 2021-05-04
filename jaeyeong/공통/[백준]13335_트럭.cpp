using namespace std;
#include <iostream>
#include <queue>
#include <vector>

int main() {
	int x, ans = 0, curL = 0;
	int n, w, L;
	queue<int> q;
	vector<pair<int,int>> onBridge;
	cin >> n >> w >> L;
	for (int i = 0; i < n; i++) {
		cin >> x;
		q.push(x);
	}
	while (!q.empty() || !onBridge.empty()) {
		ans++;
		if (!onBridge.empty() && onBridge[0].first == 0) {
			curL -= onBridge[0].second;
			onBridge.erase(onBridge.begin());
		}

		if (!q.empty()) {
			if (L >= curL + q.front()) {
				curL += q.front();
				onBridge.push_back(make_pair(w, q.front()));
				q.pop();
			}
		}

		for (int i = 0; i < onBridge.size(); i++)
			onBridge[i].first--;
	}
	cout << ans << '\n';
}