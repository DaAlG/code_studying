// SW Expert Academy
// S/W 문제해결 기본 1일차 - 1208 Flatten

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int test_case;
	int T = 10;
	vector<int> arr(100);
	int dump;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> dump;

		for (int i = 0; i < 100; i++)
			cin >> arr[i];

		for (int i = 0; i < dump; i++) {
			auto index = minmax_element(arr.begin(), arr.end());
			arr[index.second - arr.begin()]--; arr[index.first - arr.begin()]++;
		}

		auto ans = minmax_element(arr.begin(), arr.end());
		cout << "#" << test_case << " " << (*ans.second - *ans.first) << endl;
	}

	return 0;
}