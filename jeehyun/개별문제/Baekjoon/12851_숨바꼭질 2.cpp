/* BFS
 * 12851 숨바꼭질 2
 */

#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;

bool visited[MAX];

int main()
{
	int n, k;
	cin >> n >> k;

	if (n == k) {
		cout << 0 << "\n";
		cout << 1 << "\n";
		return 0;
	}

	int move[] = { -1, 1, 2 };

	queue<int> q;
	q.push(n);
	
	int time = -1;
	int min = MAX;
	int visit = 0;

	while (!q.empty()) {
		int size = q.size();
		time++;

		for (int i = 0; i < size; i++) {
			int cur = q.front(); q.pop();

			// 방문 체크를 미리 하는 것이 아니라 나중에 해서 중복 가능
			visited[cur] = true;

			if (cur == k) {
				if (min >= time) {
					min = time;
					visit++;
				}
			}

			for (int i = 0; i < 3; i++) {
				int next = (i == 2) ? cur * move[i] : cur + move[i];

				if ((next >= 0 && next < MAX) && !visited[next]) {
					q.push(next);
				}
			}
		}
	}

	cout << min << "\n";
	cout << visit << "\n";
	return 0;
}