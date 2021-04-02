/*
 * 브루트포스
 * 14889 스타트와 링크
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 0x3f3f3f
using namespace std;

int n;
int cost[21][21];
bool visited[21];

int solve(vector<int> start, int index, int sum)
{
	if (start.size() == n / 2) {
		vector<int> link;
		for (int i = 1; i <= n; i++) {
			if (!visited[i])
				link.push_back(i);
		}

		int sum_link = 0;
		for (int i = 0; i < link.size() - 1; i++) {
			for (int j = i + 1; j < link.size(); j++) {
				sum_link += cost[link[i]][link[j]] + cost[link[j]][link[i]];
			}
		}

		return abs(sum - sum_link);
	}

	int ret = INF;
	if (index <= n) {
		int add = 0;
		for (int i = 0; i < start.size(); i++) {
			add += cost[start[i]][index] + cost[index][start[i]];
		}

		// index번 사람 선택
		start.push_back(index);
		visited[index] = true;
		ret = min(ret, solve(start, index + 1, sum + add));

		// index번 사람 선택 X
		start.pop_back();
		visited[index] = false;
		ret = min(ret, solve(start, index + 1, sum));
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> cost[i][j];
		}
	}

	cout << solve(vector<int>(), 1, 0);
	return 0;
}