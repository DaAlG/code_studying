using namespace std;
#include <iostream>
#include <algorithm>
#define MAX 10000

int m[MAX], e[MAX];
pair<int, int> arr[MAX];
int main() {
	int tc, n;
	int x;
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> m[i];
		for (int i = 0; i < n; i++)
			cin >> e[i];
		for (int i = 0; i < n; i++)
			arr[i] = make_pair(-e[i], m[i]);
		sort(arr, arr + n);
		int ans = 0, cook =0;
		for (int i = 0; i < n; i++) {
			int eat = -arr[i].first;
			cook += arr[i].second;
			ans = max(ans, cook + eat);
		}
		cout << ans << '\n';
	}
	return 0;
}