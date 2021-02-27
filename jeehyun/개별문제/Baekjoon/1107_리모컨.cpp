/* 브루트포스
 * 1107 리모컨
 */

#include <iostream>
#include <string>
#include <algorithm>
#define MAX 1000000
using namespace std;

int dist[MAX];
int broken[10];

bool check(int k)
{
	if (k == 0)
		return broken[0] ? false : true;

	while (k) {
		if (broken[k % 10])
			return false;
		k /= 10;
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, tmp;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> tmp;
		broken[tmp] = true;
	}

	int ans = abs(n - 100);
	for (int i = 0; i <= MAX; i++) {
		// 0 ~ 9 버튼으로 채널을 이동할 수 있는지 확인
		if (check(i)) {
			int temp = to_string(i).length() + abs(i - n);
			ans = min(ans, temp);
		}
	}
	cout << ans;

	return 0;
}