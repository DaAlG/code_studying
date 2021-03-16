/* 브루트포스
 * 2309 일곱 난쟁이
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n = 9;
int arr[9];

bool dfs(vector<int> res, int index, int sum)
{
	if (res.size() == 7) {
		if (sum == 100) {
			for (int i = 0; i < res.size(); i++)
				cout << res[i] << '\n';
			return true;
		}
		return false;
	}

	if (index == n) return false;

	if (dfs(res, index + 1, sum))
		return true;

	res.push_back(arr[index]);
	if (dfs(res, index + 1, sum + arr[index]))
		return true;
	
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	vector<int> res;
	dfs(res, 0, 0);

	return 0;
}