/* 브루트포스
 * 10974 모든 순열
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

	int n;
	cin >> n;

	vector<int> arr;
	for (int i = 0; i < n; i++)
		arr.push_back(i + 1);

	do {
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << "\n";
	} while (next_permutation(arr.begin(), arr.end()));

	return 0;
}