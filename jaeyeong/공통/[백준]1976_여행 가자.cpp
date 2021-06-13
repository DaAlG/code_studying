using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f

vector<int> city[201];

bool bfs(int start, int dest) {
	bool flag = false;
	bool visit[201] = { false };
	queue<int> q;
	q.push(start);
	visit[start] = true;
	while (!q.empty()) {
		int c = q.front();
		q.pop();
		if (c == dest) {
			flag = true;
			break;
		}
		for (int i = 0; i < city[c].size(); i++) {
			if (!visit[city[c][i]]) {
				visit[city[c][i]] = true;
				q.push(city[c][i]);
			}
		}
	}
	return flag;
}
int main() {
	int n; // n<=200, 도시의 수
	int m; // m<=1000, 여행 계획에 속한 도시들의 수
	int a;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a;
			if (a == 1) city[i+1].push_back(j+1);
		}
	}

	vector<int> v(m);
	for (int i = 0; i < m; i++)
		cin >> v[i];

	int start, dest;
	for (int i = 1; i < m; i++) {
		start = v[i - 1];
		dest = v[i];
		if (bfs(start, dest) == false) {
			cout << "NO\n";
			break;
		}
		if (i == m - 1)
			cout << "YES\n";
	}
	return 0;
}