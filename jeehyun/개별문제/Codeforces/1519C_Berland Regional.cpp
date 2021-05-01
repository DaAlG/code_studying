#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 200001
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return a.second > b.second;
	return a.first < b.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;

		vector<pair<int, int>> student(n);
		for (int i = 0; i < n; i++) cin >> student[i].first;
		for (int i = 0; i < n; i++) cin >> student[i].second;
		
		sort(student.begin(), student.end(), cmp);

		vector<vector<long long>> teams(n + 1, vector<long long>());
		vector<long long> answer(n + 1, 0);
		
		for (int i = 0; i < n; i++) {
			teams[student[i].first].push_back(student[i].second);
		}

		for (int i = 1; i <= n; i++) {
			int size = teams[i].size();

			// 합을 미리 계산한다
			for (int j = 1; j < size; j++)
				teams[i][j] += teams[i][j - 1];

			for (int k = 1; k <= size; k++) {
				int mod = size % k;
				// 만든 팀만큼의 스킬을 더해준다
				answer[k] += teams[i][size - mod - 1];
			}
		}

		for (int i = 1; i <= n; i++) {
			cout << answer[i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}