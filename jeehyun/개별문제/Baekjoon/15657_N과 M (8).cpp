/*
 * 브루트포스
 * 15657 N과 M (8)
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int arr[9];

void go(vector<int> res, int v)
{
	if (res.size() == m) {
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = v; i <= n; i++) {
		res.push_back(arr[i]);
		go(res, i);
		res.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	sort(arr + 1, arr + n + 1);

	go(vector<int>(), 1);

	return 0;
}