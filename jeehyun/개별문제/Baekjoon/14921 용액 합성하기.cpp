/*
 * 투 포인터
 * 14921 용액 합성하기
 */

#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;

int a[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);

	int answer = 0;
	int minDiff = 200000000;

	int left = 0;
	int right = n - 1;

	while (left < right) {
		// 두 용액 혼합
		int sum = a[left] + a[right];

		// 0에 더 가까우면 업데이트
		if (abs(sum) < minDiff) {
			answer = sum;
			minDiff = abs(sum);
		}

		if (sum == 0)
			break;
		else if (sum < 0)
			left++;
		else
			right--;
	}

	cout << answer;
	return 0;
}