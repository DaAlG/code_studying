#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 100001
#define INF 987654321
using namespace std;

bool visited[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n, k;
	cin >> n >> k;

	if (n == k) {
		cout << 0 << "\n";
		cout << 1 << "\n";
		return 0;
	}

	queue<int> q;
	q.push(n);

	int moves[] = { -1, 1, 2 };
	int time = INF; // 가장 빠른 시간
	int cnt = 0; // 방법 카운트
	int t = 0; // 현재 시간

	while (!q.empty()) {
		int size = q.size();

		for (int s = 0; s < size; s++) {
			int now = q.front();
			q.pop();

			// 나중에 방문 체크를 해서 중복이 가능함
			visited[now] = true;

			if (now == k) { // 동생을 찾은 경우
				if (time > t) { // 현재의 가장 빠른 시간보다 빠르면 갱신
					time = t;
					cnt = 1;
				}
				else if (time == t) { // 가장 빠른 시간과 같으면 방법 카운트
					cnt++;
				}
				continue;
			}

			for (int i = 0; i < 3; i++) {
				int next = i < 2 ? now + moves[i] : now * moves[i];
				if (next >= 0 && next < MAX && !visited[next]) {
					q.push(next);
				}
			}
		}
		t++;
	}

	cout << time << "\n";
	cout << cnt << "\n";
	return 0;
}