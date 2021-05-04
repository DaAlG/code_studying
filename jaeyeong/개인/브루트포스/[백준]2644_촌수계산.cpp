using namespace std;
#include <iostream>
#include <vector>
#include <cstring>

int n, m;
vector<int> graph[101], ans, parent;
vector<int> arr;
int dst[2], parentArr[101] = { 0 };
bool visit[101];

void backtracking(int x, int dest) {
	if (x == dest) {
		for (int i = 0; i < arr.size(); i++)
			ans.push_back(arr[i]);
		return;
	}
	for (int i = 0; i < graph[x].size(); i++) {
		if (!visit[graph[x][i]]) {
			visit[graph[x][i]] = true;
			arr.push_back(graph[x][i]);
			backtracking(graph[x][i], dest);
			visit[graph[x][i]] = false;
			arr.pop_back();
		}
	}
}

int get(vector<int> res, int num) {
	int output = 0;
	for (int i = num; i < res.size(); i++)
		output++;
	return output;
}

bool check(int d) {
	return ans[ans.size() - 1] == d;
}

int main() {
	int x, y, answer = 0;
	vector<int> res[2];
	int from[2];

	cin >> n;
	cin >> dst[0] >> dst[1];
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
		parentArr[y] = x;
	}
	for (int i = 1; i <= n; i++)
		if (parentArr[i] == 0) parent.push_back(i);

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < parent.size(); j++) {
			ans.push_back(parent[j]);
			backtracking(parent[j], dst[i]);
			if (check(dst[i]) == false) {
				ans.clear();
				continue;
			}
			else {
				for (int j = 0; j < ans.size(); j++)
					res[i].push_back(ans[j]);
				ans.clear();
				memset(visit, false, sizeof(visit));
				from[i] = j;
				break;
			}
		}
	}

	if (from[0] != from[1]) {
		cout << "-1\n";
		return 0;
	}

	int longN = res[0].size() > res[1].size() ? 0 : 1;
	int shorter = res[0].size() < res[1].size() ? res[0].size() : res[1].size();
	if (res[0][0] != res[1][0])
		answer = -1;
	else {
		for (int i = 0; i < shorter; i++) {
			if (res[0][i] != res[1][i]) {
				answer += get(res[0], i);
				answer += get(res[1], i);
				break;
			}
			if (i == shorter - 1) {
				answer = get(res[longN], i)-1;
			}
		}
		cout << answer << '\n';
	}
}