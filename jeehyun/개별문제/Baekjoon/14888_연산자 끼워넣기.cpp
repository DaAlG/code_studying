/* 브루트포스
 * 14888 연산자 끼워넣기
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calc(vector<int> &arr, vector<int> &ops)
{
	int n = arr.size();
	int sum = arr[0];

	for (int i = 1; i < n; i++) {
		switch (ops[i-1]) {
		case 0:
			sum += arr[i];
			break;
		case 1:
			sum -= arr[i];
			break;
		case 2:
			sum *= arr[i];
			break;
		case 3:
			sum /= arr[i];
			break;
		}
	}

	return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	vector<int> ops;
	for (int i = 0; i < 4; i++) {
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; j++)
			ops.push_back(i);
	}
	sort(ops.begin(), ops.end());

	vector<int> res;
	do {
		int sum = calc(arr, ops);
		res.push_back(sum);
	} while (next_permutation(ops.begin(), ops.end()));

	auto answer = minmax_element(res.begin(), res.end());
	cout << *answer.second << '\n' << *answer.first;
	return 0;
}