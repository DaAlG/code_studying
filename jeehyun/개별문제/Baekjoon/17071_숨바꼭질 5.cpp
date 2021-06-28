/*
 * 그래프
 * 17071 숨바꼭질 5
 */

#include <iostream>
#include <queue>
#define MAX 500001
using namespace std;

int n, k;
bool visited[MAX][2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	if (n == k) {
		cout << 0;
		return 0;
	}

	queue<int> q;
	q.push(n);
	visited[n][0] = true;

	int move[] = { -1, 1, 2 };
	int time = 0;

	while (!q.empty() && k < MAX) {
		int size = q.size();
		while (size--) {
			int now = q.front();
			q.pop();

			// 현재 동생과 같은 위치에 있거나 이미 방문했던 곳이면 종료
			if (now == k || visited[k][time % 2]) {
				cout << time;
				return 0;
			}

			for (int i = 0; i < 3; i++) {
				int next = (i == 2) ? now * move[i] : now + move[i];

				if (next < 0 || next >= MAX || visited[next][!(time % 2)]) continue;

				visited[next][!(time % 2)] = true;
				q.push(next);
			}
		}

		time++;
		k += time;
	}
	cout << -1;
	return 0;
}