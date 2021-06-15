/*
 * 정렬
 * 2108 통계학
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	map<int, int> md;
	int sum = 0;
	int maxCnt = 0;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		md[a[i]]++;
		maxCnt = max(maxCnt, md[a[i]]);
	}

	sort(a.begin(), a.end());

	// 산술평균 : 소수점 이하 첫째 자리에서 반올림
	cout << round((double)sum / n) << '\n';

	// 중앙값
	cout << a[n / 2] << '\n';

	int mode = 0;
	int tmp = 0;

	// 중복 제거
	a.erase(unique(a.begin(), a.end()), a.end());

	// 최빈값 구하기
	for (int i = 0; i < n; i++) {
		if (md[a[i]] == maxCnt) {
			tmp++;
			mode = a[i];
			if (tmp == 2) {
				break;
			}
		}
	}
	cout << mode << '\n';

	// 최댓값, 최솟값 차이
	cout << a.back() - a.front() << '\n';

	return 0;
}