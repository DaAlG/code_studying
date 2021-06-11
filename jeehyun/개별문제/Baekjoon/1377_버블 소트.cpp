/*
 * 정렬
 * 1377 버블 소트
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

	int n;
	cin >> n;

	vector<pair<int, int>> a;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		a.push_back({k, i});
	}

	sort(a.begin(), a.end());

	int maxCnt = -1;
	for (int i = 0; i < n; i++) {
		// 정렬 후 인덱스 - 정렬 전 인덱스 = 좌측으로 이동한 횟수 - 1
		maxCnt = max(a[i].second - i, maxCnt);
	}
	
	// 좌측 이동 횟수 중 최댓값이 버블 소트 횟수이므로 1을 더하면 된다
	cout << maxCnt + 1;
	return 0;
}