/*
 * 이분탐색
 * 1920 수 찾기 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, tmp;
	cin >> n;

	vector<int> arr;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		int target;
		cin >> target;

		int left = 0;
		int right = n - 1;
		bool exist = false;
		
		while (left <= right) {
			int mid = (left + right) / 2;

			if (arr[mid] == target) {
				exist = true;
				break;
			}
			else if (arr[mid] > target) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}

		if (exist)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}

	return 0;
}