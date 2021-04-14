/*
 * 브루트포스
 * 15651 N과 M (3)
 */

#include <iostream>
#include <vector>
using namespace std;

int n, m;

void go(vector<int> arr)
{
	if (arr.size() == m) {
		for (int i = 0; i < arr.size(); i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		arr.push_back(i);
		go(arr);
		arr.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	go(vector<int>());

	return 0;
}