using namespace std;
#include <iostream>
#include <queue>

int visit[100001];


int bfs(int start, int dst) {
	queue<int> q;
	int max = 100000;
	int depth = 0;
	q.push(start);
	visit[start] = true;

	while (q.empty()==false) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int v = q.front();
			q.pop();
			if (v == dst) {
				queue<int> empty;
				q = empty;
				return depth;
			}
			//visit�迭�� Ȯ���Ͽ� �̹� �湮�� �������� �˻�. �迭 ���� ���� ���� ���.
			if (v - 1 >= 0 && !visit[v - 1]) {
				q.push(v - 1);
				visit[v - 1] = true;
			}
			if (v + 1 <= max && !visit[v + 1]) {
				q.push(v + 1);
				visit[v + 1] = true;
			}
			if (v * 2 <= max && !visit[v * 2]) {
				q.push(v * 2);
				visit[v * 2] = true;
			}
		}
		depth++;
	}
	
}
int main() {
	int n, k;
	cin >> n >> k;
	cout << bfs(n, k);
}