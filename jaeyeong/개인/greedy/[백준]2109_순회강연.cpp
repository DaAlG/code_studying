using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

struct univ {
	int d, p;
};

int main() {
	int n, d, p;
	cin >> n;
	vector<univ> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].p >> v[i].d;

	sort(v.begin(), v.end(), [](univ a, univ b) {
		return a.d > b.d;
		});
	priority_queue<int> q;
	int ans = 0, k=0;
	for (int i = 10000; i >= 1; i--) {
		while (k < n && v[k].d == i) { //i일까지 갈 수 있는 대학 후보
			q.push(v[k].p);
			k++;
		}
		if (!q.empty()) { //i일에 어떤 학교를 갈지 결정
			ans += q.top();
			q.pop();
		}
	}
	cout << ans << '\n';
}