/* 그래프
 * 13023 ABCDE
 */

#include <iostream>
#include <vector>
#define MAX 2000
using namespace std;

int n, m;
vector<int> arr[MAX];
bool visited[MAX];
int answer = 0;

bool dfs(int cur, int cnt)
{
	if (cnt == 4) {
		answer = 1;
		return true;
	}

	visited[cur] = true;

	for (int i = 0; i < arr[cur].size(); i++) {
		int next = arr[cur][i];

		if (!visited[next] && dfs(next, cnt + 1))
			return true;
	}

	visited[cur] = false;

	return false;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	for (int i = 0; i < m; i++) {
		dfs(i, 0);
	}

	cout << answer;
	return 0;
}