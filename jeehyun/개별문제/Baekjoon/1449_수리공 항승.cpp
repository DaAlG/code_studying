/*
 * 그리디
 * 1449 수리공 항승
 */

#include <iostream>
#include <algorithm>
#define MAX 1001

using namespace std;

int arr[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, L;
	cin >> n >> L;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// 오름차순 정렬
	sort(arr, arr + n);

	int cnt = 1; // 테이프 개수
	int left = 0;
	int right = 1;

	while (right < n) {
		if (arr[right] - arr[left] < L) {
			right++;
		}
		else {
			cnt++;
			left = right;
		}
	}
	cout << cnt;

	return 0;
}