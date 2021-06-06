using namespace std;
#include <iostream>
#include <queue>

int n;
int zero, one;

int main() {
	cin >> n;
	priority_queue<int> pos, neg;
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (t == 1) one++;
		else if (t < 0) neg.push(-t);
		else if (0 < t) pos.push(t);
		else zero++;
	}

	long long sum = 0;

	while (1 < pos.size()) {
		int x = pos.top();
		pos.pop();
		int y = pos.top();
		pos.pop();
		sum += x * y;
	}
	if (!pos.empty()) {
		sum += pos.top();
		pos.pop();
	}
	while (1 < neg.size()) {
		int x = neg.top();
		neg.pop();
		int y = neg.top();
		neg.pop();
		sum += x * y;
	}
	if (!neg.empty()) {
		if (zero > 0)
			neg.pop();
		else
			sum -= neg.top();
	}
	sum += 1 * one;
	cout << sum << '\n';
}