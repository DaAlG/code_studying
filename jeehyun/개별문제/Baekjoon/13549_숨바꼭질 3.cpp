/* 그래프
 * 13549 숨바꼭질 3
 * 0-1 BFS
 */

#include <iostream>
#include <deque>
#include <algorithm>
#define MAX 100001
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	if (N == K) {
		cout << 0;
		return 0;
	}

	int move[] = { 2, 1, -1};
	int dist[MAX];
	fill(dist, dist + MAX, -1);

	deque<int> q;
	q.push_front(N);
	dist[N] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop_front();

		for (int i = 0; i < 3; i++) {
			int next = (i == 0) ? now * move[i] : now + move[i];

			if (next < 0 || next > MAX) continue;
			if (dist[next] != -1) continue;

			if (i == 0) {
				dist[next] = dist[now];
				q.push_front(next);
			}
			else {
				dist[next] = dist[now] + 1;
				q.push_back(next);
			}

			if (next == K) {
				cout << dist[next];
				return 0;
			}
		}
	}

	return 0;
}