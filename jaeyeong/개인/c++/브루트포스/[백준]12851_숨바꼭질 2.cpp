using namespace std;
#include <iostream>
#include <queue>

bool visit[100001];
int n, k;

void bfs() {
	int answer = 0, answert = -1;
	queue<pair<int, int>> q;
	q.push(make_pair(0, n));
	while (!q.empty()) {
		int t = q.front().first;
		int c = q.front().second;
		q.pop();

		visit[c] = true;
		if (c == k) {
			if (answert == t && answert!=-1) answer++;
			else if (answert == -1) {
				answert = t;
				answer++;
			}
		}
		
		
		int next = c * 2;
		if (0 <= next && next <= 100000) {
			if(!visit[next])
			q.push(make_pair(t + 1, next));
		}

		next = c + 1;
		if (0 <= next) {
			if (!visit[next])
			q.push(make_pair(t + 1, next));
		}

		next = c - 1;
		if (next <= 100000) {
			if (!visit[next])
			q.push(make_pair(t + 1, next));
		}


	}
	cout << answert << '\n' << answer << '\n';
}
int main() {
	cin >> n >> k;
	visit[n] = true;
	bfs();
}