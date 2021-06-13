/*
 * 이분 탐색
 * 2470 두 용액
 */

#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int arr[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// 오름차순 정렬
	sort(arr, arr + n);

	// 포인터
	int left = 0;
	int right =	n - 1;

	// 특성값이 0에 가장 가까운 용액 정보
	int diff = 2000000000;
	int minx = 0;
	int miny = n - 1;

	// 투 포인터
	while (left < right) {
		int sum = arr[left] + arr[right];

		// 0과의 차가 가장 작은 용액 찾기
		if (abs(sum) < diff) {
			minx = left;
			miny = right;
			diff = abs(sum);
		}
		
		// 특성값이 0이면 탐색 종료
		if (sum == 0)
			break;
		else if (sum < 0)
			left++;
		else
			right--;
	}
	cout << arr[minx] << ' ' << arr[miny];
	return 0;
}