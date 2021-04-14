using namespace std;
#include <iostream>

int n, k;
int cnt[100001];
int a[200002];

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int s = 1, e = 1, ans = 0;
	while (e <= n && s <= e) {
		while (e <= n && cnt[a[e]] <= k) {
			if (cnt[a[e]] == k)
				break;
			cnt[a[e]]++;
			ans = max(ans, e - s + 1);
			e++;
		}
		while (s < e) {
			if (cnt[a[s]] == k) {
				cnt[a[s++]]--;
				break;
			}
			cnt[a[s++]]--;
		}
	}
	cout << ans << '\n';
}