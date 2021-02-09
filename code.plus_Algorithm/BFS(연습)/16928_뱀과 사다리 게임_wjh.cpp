/* 
 * 100개의 칸으로 나누어져 있는 게임
 * 1에서 100으로 가야함
 * 주사위를 굴려 나온 수만큼 이동할 수 있으며, 도착한 칸이 사다리인 경우에는 사다리를 타고 더 큰 번호의 칸으로,
 * 뱀인 경우에는 더 작은 번호의 칸으로 이동
 * 주사위에 나온 수를 정할 수 있을 때, 최소 몇 번 굴려야 하는지 구하는 문제
 * 최소를 구하는 문제이기 때문에 BFS로 해결 가능
 */

#include <iostream>
#include <algorithm>
#include <queue>
#define next _next

using namespace std;

int dist[101];
int next[101];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= 100; i++) {
		next[i] = i;
		dist[i] = -1;
	}

	// 사다리
	while (n--) {
		int x, y;
		cin >> x >> y;
		next[x] = y;
	}

	// 뱀
	while (m--) {
		int x, y;
		cin >> x >> y;
		next[x] = y;
	}

	// 시작
	dist[1] = 0;
	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int x = q.front; q.pop();
		for (int i = 1; i <= 6; i++) {
			int y = x + i;

			if (y > 100)
				continue;

			y = next[y];

			// BFS
			if (dist[y] == -1) {
				dist[y] = dist[x] + 1;
				q.push(y);
			}
		}
	}
	cout << dist[100] << endl;
	return 0;
}