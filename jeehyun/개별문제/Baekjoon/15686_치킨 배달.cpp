/*
 * 브루트포스
 * 15686 치킨 배달
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAX 51
#define INF 0x3f3f3f
using namespace std;

int n, m;
int map[MAX][MAX];
int dist[2 * MAX][13];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	vector<pair<int, int>> chicken;
	vector<pair<int, int>> home;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];

			if (map[i][j] == 1) {
				home.push_back({i, j});
			}
			else if (map[i][j] == 2) {
				chicken.push_back({i, j});
			}
		}
	}

	memset(dist, INF, sizeof(dist));

	// 집과 각 치킨집과의 거리 계산
	for (int i = 0; i < chicken.size(); i++) {
		for (int j = 0; j < home.size(); j++) {
			int d = abs(home[j].first - chicken[i].first) + abs(home[j].second - chicken[i].second);
			dist[j][i] = min(dist[j][i], d);
		}
	}

	// 치킨집 선택을 위한 벡터
	vector<int> perm(chicken.size(), 0);
	for (int i = 0; i < m; i++)
		perm[i] = 1;
	sort(perm.begin(), perm.end());

	int answer = INF;
	do {
		int total = 0;
		for (int i = 0; i < home.size(); i++) {
			int d = INF;
			for (int j = 0; j < perm.size(); j++) {
				if (perm[j]) { // 집의 치킨 거리
					d = min(d, dist[i][j]);
				}
			}
			total += d;
		}
		answer = min(answer, total);
	} while (next_permutation(perm.begin(), perm.end()));
	cout << answer;

	return 0;
}