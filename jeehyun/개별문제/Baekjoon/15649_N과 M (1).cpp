/*
 * 브루트포스
 * 15649 N과 M (1)
 */

#include <iostream>
#include <vector>
using namespace std;

int n, m;
bool visited[9];

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
		if (!visited[i]) {
			arr.push_back(i);
			visited[i] = true;
			go(arr);
			arr.pop_back();
			visited[i] = false;
		}
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