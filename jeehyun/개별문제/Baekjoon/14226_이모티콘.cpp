/* 그래프
 * 14226 이모티콘
 */

#include <iostream>
#include <queue>
using namespace std;

int s;
bool visited[1001][1001];

int main()
{
	int s;
	cin >> s;

	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(1, 0), 0));
	visited[1][0] = true;

	while (!q.empty()) {
		int cnt = q.front().first.first;
		int clipboard = q.front().first.second;
		int time = q.front().second;
		q.pop();

		if (cnt == s) {
			cout << time;
			return 0;
		}

		// 복사
		if (!visited[cnt][cnt]) {
			visited[cnt][cnt] = true;
			q.push(make_pair(make_pair(cnt, cnt), time + 1));
		}

		// 붙여넣기
		if (clipboard > 0) {
			if (cnt + clipboard <= 1000 && !visited[cnt + clipboard][clipboard]) {
				visited[cnt + clipboard][clipboard] = true;
				q.push(make_pair(make_pair(cnt + clipboard, clipboard), time + 1));
			}
		}

		// 삭제
		if (cnt > 2 && !visited[cnt - 1][clipboard]) {
			visited[cnt - 1][clipboard] = true;
			q.push(make_pair(make_pair(cnt - 1, clipboard), time + 1));
		}
	}

	return 0;
}