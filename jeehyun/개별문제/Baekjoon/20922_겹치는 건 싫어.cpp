/*
 * 투 포인터
 * 20922 겹치는 건 싫어
 */

#include <iostream>
#include <algorithm>
#define AMAX 200001
#define DMAX 100001
using namespace std;

int arr[AMAX];
int dup[DMAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int answer = 0;
	int left = 1;
	int right = 1;

	while (left <= right && right <= n) {
		if (dup[arr[right]] < k) {
			dup[arr[right++]]++;
			answer = max(answer, right - left);
		}
		else if (dup[arr[right]] == k) {
			dup[arr[left++]]--;
		}
	}
	cout << answer;

	return 0;
}