/*
 * 백트래킹
 * 15666 N과 M (12)
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> arr;

void go(vector<int> res, int v)
{
	if (res.size() == m) {
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = v; i < arr.size(); i++) {
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
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		arr.push_back(k);
	}
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	go(vector<int>(), 0);

	return 0;
}