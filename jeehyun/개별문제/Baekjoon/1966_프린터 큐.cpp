/*
 * 자료구조
 * 1966 프린터 큐
 */

#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, n, m;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> n >> m;

		vector<int> arr(n);
		queue<pair<int, int>> q;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			q.push({ i, i });
		}

		int seq = 0;
		while (!q.empty()) {
			int org = q.front().first;
			int cur = q.front().second;
			q.pop();

			bool check = true;
			for (int i = cur + 1; i < arr.size(); i++) {
				if (arr[cur] < arr[i]) {
					check = false;
					break;
				}
			}

			if (check) {
				seq++;
				if (org == m) {
					cout << seq << '\n';
					continue;
				}
			}
			else {
				arr.push_back(arr[org]);
				q.push({ org, arr.size() - 1 });
			}
		}
	}

	return 0;
}