using namespace std;
#include <iostream>
#include <queue>

bool visit[100001];
int n, k;

void bfs() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push(make_pair(0,n));
	while (!q.empty()) {
		int t = q.top().first;
		int c = q.top().second;
		q.pop();
		if (c == k) {
			cout << t << '\n';
			break;
		}

		int next = c * 2;
		if (0 <= next && next <= 100000) {
			if (!visit[next]) {
				visit[next] = true;
				q.push(make_pair(t, next));
			}
		}

		next = c + 1;
		if (0 <= next) {
			if (!visit[next]) {
				visit[next] = true;
				q.push(make_pair(t+1, next));
			}
		}

		next = c - 1;
		if (next <= 100000) {
			if (!visit[next]) {
				visit[next] = true;
				q.push(make_pair(t+1, next));
			}
		}


	}
}
int main() {
	cin >> n >> k;
	visit[n] = true;
	bfs();
}