/* Binary Search, Ternary Seacrh
 * 1654 랜선 자르기
 * 랜선을 모두 N개의 같은 길이의 랜선으로 만들고 싶다
 * 따라서 K개의 랜선을 잘라서 만들어야 한다
 * 이때 만들 수 있는 최대 랜선의 길이
 */

#include <iostream>
#include <algorithm>
#define MAX 10001
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k, n;
	long long arr[MAX];
	cin >> k >> n;

	for (int i = 0; i < k; i++)
		cin >> arr[i];
	sort(arr, arr + k);

	// Binary Search
	// 입력받은 랜선의 길이를 binary search하는 것이 아니라
	// 1부터 랜선 최대길이인 arr[k-1]까지를 binary search하는 것!
	long long left = 1, right = arr[k - 1];
	long long answer = 0;
	
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long sum = 0;

		for (int i = 0; i < k; i++)
			sum += arr[i] / mid;

		// 합한 갯수가 N개보다 적을 경우
		if (sum < n) {
			// 자르는 길이를 줄여본다
			right = mid - 1;
		}
		else {
			if (answer < mid)
				answer = mid;
			// 자르는 길이를 늘려본다
			left = mid + 1;
		}
	}
	cout << answer;

	return 0;
}