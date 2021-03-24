using namespace std;
#include <iostream>
#include <queue>

int board[101];
bool visit[101];

int bfs() {
	queue<int> q;
	int count = 0, max, togo;
	q.push(1);
	visit[1] = true;
	while (q.empty() == false) {
		int size = q.size();

		for (int i = 0; i < size; i++) {
			int v = q.front();
			q.pop();

			if (v == 100) return count;

			max = v < 95 ? 6 : 100 - v;
			for (int j = 1; j <= max; j++) {
				togo = board[v + j] != 0 ? board[v + j] : v + j;
				if (visit[togo] == 0) {
					q.push(togo);
					visit[togo] = 1;
				}
			}
		}
		count++;
	}
}
int main() {
	int n, m, x, y;
	cin >> n >> m;
	for (int i = 0; i < (n + m); i++) {
		cin >> x >> y;
		board[x] = y;
	}
	cout << bfs();
}