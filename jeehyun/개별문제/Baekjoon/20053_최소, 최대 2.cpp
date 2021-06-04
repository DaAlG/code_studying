/*
 * 구현
 * 20053 최소, 최대 2
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

	int T, n;
	cin >> T;
	
	while (T--) {
		cin >> n;
		
		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		sort(arr.begin(), arr.end());
		cout << arr.front() << ' ' << arr.back() << '\n';
	}

	return 0;
}