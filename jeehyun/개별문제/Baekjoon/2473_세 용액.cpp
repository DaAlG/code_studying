/*
 * 이분 탐색
 * 2473 세 용액
 */

#include <iostream>
#include <algorithm>
#include <climits> // LLONG_MAX
using namespace std;

long long a[5001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	
	long long minDiff = LLONG_MAX; // or 3000000000
	int minLeft, minMid, minRight;

	// 첫 번째 용액 고정
	for (int i = 0; i < n - 2; i++) {
		int left = i + 1;
		int right = n - 1;
		// 두 번째, 세 번째 용액 찾기
		while (left < right) {
			long long sum = a[i] + a[left] + a[right];
			if (abs(sum) < minDiff) {
				minDiff = abs(sum);
				minLeft = i;
				minMid = left;
				minRight = right;
			}
			
			if (sum < 0)
				left++;
			else if (sum > 0)
				right--;
			else {
				i = n;
				break;
			}
		}
	}
	cout << a[minLeft] << ' ' << a[minMid] << ' ' << a[minRight];
	return 0;
}