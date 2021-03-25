/* BFS
 * 13913 숨바꼭질 4
 */

#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 100001
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	if (n == k) {
		cout << 0 << "\n";
		cout << n << "\n";
		return 0;
	}

	int move[] = { -1, 1, 2 };
	int dist[MAX];
	int parent[MAX];
	fill(dist, dist + MAX, -1);
	fill(parent, parent + MAX, -1);

	queue<int> q;
	q.push(n);
	dist[n] = 0;

	while (!q.empty()) {
		int cur = q.front(); 
		q.pop();

		for (int i = 0; i < 3; i++) {
			int next = (i == 2) ? cur * move[i] : cur + move[i];

			if (next < 0 || next >= MAX) continue;
			if (dist[next] != -1) continue;

			q.push(next);
			dist[next] = dist[cur] + 1;
			parent[next] = cur;

			if (next == k) {
				vector<int> path;
				path.push_back(next);
				for (int i = k; parent[i] != -1; i = parent[i]) {
					path.push_back(parent[i]);
				}

				cout << dist[next] << "\n";
				for (int i = path.size() - 1; i >= 0; i--) {
					cout << path[i] << " ";
				}
				return 0;
			}
		}
	}

	return 0;
}