#include <iostream>
#include <vector>
#define MAX 300001
using namespace std;

vector<int> graph[MAX];
int set[MAX];

void dfs(int v, int num) 
{
	set[v] = num;

	for (int next : graph[v]) {
		if (set[next] == 0)
			dfs(next, num);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n - 2; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int num = 1;
	for (int i = 1; i <= n; i++) {
		if (set[i] == 0) {
			dfs(i, num++);
		}
	}


	for (int i = 2; i <= n; i++) {
		if (set[i - 1] != set[i]) {
			cout << i - 1 << " " << i << "\n";
			break;
		}
	}
	return 0;
}