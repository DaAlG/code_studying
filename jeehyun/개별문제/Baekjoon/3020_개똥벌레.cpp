/*
 * 이분 탐색
 * 3020 개똥벌레
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, h;
	cin >> n >> h;

	vector<int> obs1(n / 2); // 석순
	vector<int> obs2(n / 2); // 종유석
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) cin >> obs1[i / 2];
		else cin >> obs2[i / 2];
	}

	sort(obs1.begin(), obs1.end());
	sort(obs2.begin(), obs2.end());

	int answer = 2000000;
	int cnt = 0;

	for (int i = 1; i <= h; i++) {
		int tmp = 0; // 장애물 개수

		// 개똥벌레가 파괴하는 석순 개수
		auto lower = lower_bound(obs1.begin(), obs1.end(), i);
		tmp += distance(lower, obs1.end());

		// 개똥벌레가 파괴하는 종유석 개수
		lower = lower_bound(obs2.begin(), obs2.end(), h - i + 1);
		tmp += distance(lower, obs2.end());

		if (tmp == answer) {
			cnt++;
		}
		else if (tmp < answer) {
			answer = tmp;
			cnt = 1;
		}
	}
	cout << answer << ' ' << cnt;

	return 0;
}