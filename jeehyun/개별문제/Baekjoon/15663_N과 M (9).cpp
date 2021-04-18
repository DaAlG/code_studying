/*
 * 브루트포스
 * 15663 N과 M (9)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int n, m;
int arr[9];
bool visited[9];
set<string> st;

void go(vector<int> res, int v)
{
	if (res.size() == m) {
		string s;
		for (int k : res) {
			s += to_string(k);
		}

		if (st.find(s) == st.end()) {
			for (int i = 0; i < res.size(); i++) {
				cout << res[i] << ' ';
			}
			cout << '\n';
			st.insert(s);
		}
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			res.push_back(arr[i]);
			go(res, i);
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

	go(vector<int>(), 0);

	return 0;
}