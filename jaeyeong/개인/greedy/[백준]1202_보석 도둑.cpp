using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

/*
이 방법 말고도 가방과 보석을 한 배열에 넣고 정렬한 뒤
(1,23), (2,99), 2, (5,65), 10
가방값 앞들의 보석들을 후보큐(priority queue)에 넣고 가장 높은 가치의 후보를 골라내는 방법도 있음.
*/
struct jewel {
	int m, v;
};
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;

	vector<jewel> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i].m >> a[i].v;
	sort(a.begin(), a.end(), [](jewel u, jewel v) {
		return u.v > v.v;
		});

	multiset<int> bag;
	for (int i = 0; i < k; i++) {
		int t;
		cin >> t;
		bag.insert(t);
	}

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		auto it = bag.lower_bound(a[i].m);
		if (it != bag.end()) {
			ans += a[i].v;
			bag.erase(it);
		}
	}
	cout << ans << '\n';
}