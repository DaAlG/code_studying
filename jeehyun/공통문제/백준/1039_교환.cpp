#include <iostream>
#include <string>
#include <queue>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string n;
	int k;
	cin >> n >> k;

	set<string> visited;

	queue<string> q;
	q.push(n);
	int cnt = 0;
	int answer = -1;

	while (!q.empty()) {
		int size = q.size();
		for (int s = 0; s < size; s++) {
			string now = q.front();
			q.pop();

			if (cnt == k) { // 연산을 k번 했을 때 최댓값 찾기
				answer = max(answer, stoi(now));
			}

			for (int i = 0; i < now.size(); i++) {
				for (int j = i + 1; j < now.size(); j++) {
					string next = now;
					swap(next[i], next[j]);

					if (next[0] == '0') continue; // 0으로 시작하면 안됨
					if (!visited.count(next)) {
						visited.insert(next);
						q.push(next);
					}
				}
			}
		}
		visited.clear();

		if (cnt >= k) break;
		cnt++;
	}

	cout << answer;

	return 0;
}