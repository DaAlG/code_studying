/*
 * 구현
 * 10773 제로
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;

		if (k == 0 && !arr.empty())
			arr.pop_back();
		else
			arr.push_back(k);
	}

	int answer = 0;
	for (int k : arr) {
		answer += k;
	}
	cout << answer;

	return 0;
}