/*
 * 그래프
 * 1516 게임 개발
 */

#include <iostream>
#include <vector>
#include <queue>
#define MAX 501
#define INF 50000000
using namespace std;

int n;
vector<int> graph[MAX];
int cnt[MAX]; // 선행 정점 개수
int t[MAX]; // 건설시간
int dp[MAX]; // 최소 건설시간

void topologicalSort()
{
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0) {
			dp[i] = t[i];
			q.push(i);
		}
	}

	for (int i = 0; i < n; i++) {
		int v = q.front();
		q.pop();

		for (int j = 0; j < graph[v].size(); j++) {
			int next = graph[v][j];

			cnt[next]--;

			// 건물을 짓기 위해 걸리는 최소 시간
			// 앞순서 건물들이 모두 건설 완료되어야지만 건설을 시작할 수 있으므로 최댓값을 찾는다
			dp[next] = max(dp[next], dp[v] + t[next]);

			if (cnt[next] == 0) {
				q.push(next);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
		
		int pre;
		while (cin >> pre) {
			if (pre == -1)
				break;

			graph[pre].push_back(i);
			cnt[i]++;
		}
	}

	topologicalSort();

	for (int i = 1; i <= n; i++) {
		cout << dp[i] << '\n';
	}

	return 0;
}