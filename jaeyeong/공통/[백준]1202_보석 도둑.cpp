using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

/*
�� ��� ���� ����� ������ �� �迭�� �ְ� ������ ��
(1,23), (2,99), 2, (5,65), 10
���氪 �յ��� �������� �ĺ�ť(priority queue)�� �ְ� ���� ���� ��ġ�� �ĺ��� ��󳻴� ����� ����.
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