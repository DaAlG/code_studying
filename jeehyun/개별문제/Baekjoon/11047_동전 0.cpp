/* 그리디
 * 11047 동전 0
 * 동전을 적절히 사용해서 그 가치의 합을 K로 만들려고 할 때,
 * 필요한 동전 개수의 최솟값 출력
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 시간 오래 걸림
void greedy(int sum, int cnt)
{
	bool solved = false;
	for (int i = n - 1; i >= 0 && !solved; i--) {
		int res = sum + coin[i];

		if (res > k)
			continue;
		else if (res < k) {
			greedy(res, cnt + 1);
			return;
		}
		else {
			ans = min(ans, cnt + 1);
			solved = true;
			return;
		}
	}
}
*/

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, tmp;
	vector<int> coin;
	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		coin.push_back(tmp);
	}

	//greedy(0, 0);
	
	int ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (coin[i] <= k) {
			ans += k / coin[i];
			k %= coin[i];
		}
	}
	cout << ans;

	return 0;
}