using namespace std;
#include <iostream>
#include <cstring>
#include <queue>
#define INF 0x3f3f3f3f

/*
* ★문제의 이해, 문제에서 최종적으로 원하는 것을 주목하자
* 플로이드를 응요해서 풀면 시간초과가 났던 이유
* 전체 경로의 최소 값을 다 구하고 시도하면 시간 초과 
* => 만약 a -> c로 가는데 도중 경로가 a -> b , b -> c 라면 a -> b 가 k보다 작을 때 이미 a -> c는 k이상의 값을 가질 수 없게 된다.
* 따라서 이를 이용해서 모든 간선의 최소거리 미리 찾을 필요 없이 탐색에서 k 이상이면 큐에 넣고 카운트 올리는 식으로 돌리면 됨.
*/
int n, q;
int visit[5001];
vector<pair<int,int>> arr[5001];//노드, 유사도

void bfs(int k, int v) {
	int cnt = 0;
	queue<int> q;
	visit[v] = 1;
	q.push(v);
	while (!q.empty()) {
		int c = q.front();
		q.pop();
		for (int i = 0; i < arr[c].size(); i++) {
			if (!visit[arr[c][i].first]) {
				if (arr[c][i].second >= k) {
					cnt++;
					visit[arr[c][i].first] = 1;
					q.push(arr[c][i].first);
				}
			}
		}
	}
	cout << cnt << '\n';
}
int main() {
	int a, b, c;
	cin >> n >> q;
	for (int i = 0; i < (n-1); i++) {
		cin >> a >> b >> c;
		arr[a].push_back(make_pair(b, c));
		arr[b].push_back(make_pair(a, c));
	}

	int k, v;
	while (q--) {
		memset(visit, 0, sizeof(visit));
		cin >> k>> v;
		bfs(k, v);
	}
	return 0;
}