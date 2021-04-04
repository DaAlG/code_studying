/* 
 * BFS
 * 4991 로봇 청소기
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAX 20
#define INF 0x3f3f3f
using namespace std;

int w, h;
char room[MAX][MAX];
int res[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int bfs(pair<int, int> start, pair<int, int> end)
{
	memset(visited, false, sizeof(visited));

	queue<pair<pair<int, int>, int>> q;
	q.push({ start, 0 });
	visited[start.first][start.second] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dist = q.front().second;
		q.pop();

		if (x == end.first && y == end.second)
			return dist;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
			if (visited[nx][ny]) continue;

			if (room[nx][ny] == '*' || room[nx][ny] == '.' || room[nx][ny] == 'o') {
				visited[nx][ny] = true;
				q.push({ {nx ,ny}, dist + 1 });
			}
		}
	}

	return -1;
}


int main()
{
	while (cin >> w >> h) {
		if (w == 0 && h == 0)
			break;

		vector<pair<int, int>> dirty;
		pair<int, int> start;
		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf(" %c", &room[i][j]);

				if (room[i][j] == 'o')
					start = {i, j};
				else if	(room[i][j] == '*')
					dirty.push_back({ i, j });
			}
		}
		dirty.insert(dirty.begin(), start);

		memset(res, 0, sizeof(res));

		// BFS를 통해 로봇의 시작위치와 더러운 칸, 각 더러운 칸 사이의 거리를 구한다
		for (int i = 0; i < dirty.size(); i++) {
			for (int j = 0; j < dirty.size(); j++) {
				if (i == j || res[i][j] != 0)
					continue;

				int dist = bfs(dirty[i], dirty[j]);
				// 배열 res에 거리를 저장
				res[i][j] = res[j][i] = dist;
			}
		}

		vector<int> perm; // 더러운 칸의 방문 순열을 위한 벡터
		for (int i = 0; i < dirty.size(); i++)
			perm.push_back(i);

		int answer = INF;
		bool check = true;
		do {
			int total_dist = 0;
			for (int i = 1; i < perm.size(); i++) {
				if (res[perm[i - 1]][perm[i]] == -1) {
					// 방문할 수 없는 더러운 칸이 있다면 false
					answer = total_dist = INF;
					check = false;
					break;
				}
				total_dist += res[perm[i - 1]][perm[i]];
			}
			answer = min(answer, total_dist);
		} while (check && next_permutation(perm.begin() + 1, perm.end())); // 시작은 반드시 시작위치부터이므로 perm.begin() + 1
		

		if (answer == INF)
			cout << -1 << '\n';
		else
			cout << answer << '\n';
	}

	return 0;
}