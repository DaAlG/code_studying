/*
 * 브루트포스
 * 15654 N과 M (5)
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int arr[9];
bool visited[9];

void go(vector<int> res)
{
	if (res.size() == m) {
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			res.push_back(arr[i]);
			go(res);
			visited[i] = false;
			res.pop_back();
		}
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

	go(vector<int>());

	return 0;
}