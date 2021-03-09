//플로이드 와샬 알고리즘: 모든 정점에서 모든 정점으로 거리 구할때!
using namespace std;
#include <iostream>
#include <vector>
#define INF 0x3f3f3f3f



int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	int answer = INF;
	//결과 그래프, map 초기화
	int d[201][201], map[201][201];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				map[i][j] = 0;
				d[i][j] = 0;
			}
			else {
				map[i][j] = INF;
				d[i][j] = INF;
			}
		}
	}
	for (int i = 0; i < fares.size(); i++) {
		map[fares[i][0]][fares[i][1]] = fares[i][2];
		map[fares[i][1]][fares[i][0]] = fares[i][2];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			d[i][j] = map[i][j];
		}
	}

	// k = 거쳐가는 노드
	for (int k = 1; k <= n; k++) {
		// i = 출발 노드
		for (int i = 1; i <= n; i++) {
			// j = 도착 노드
			for (int j = 1; j <= n; j++) {
				if (d[i][k] + d[k][j] < d[i][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	for (int mid = 1; mid <= n; mid++) {
		if (d[mid][a] == INF || d[mid][b] == INF || d[s][mid] == INF)
			continue;
		int temp = d[s][mid] + d[mid][a] + d[mid][b];
		answer = min(answer, temp);
	}

	return answer;
}

int main() {
	int n = 6, s = 4, a = 6, b = 2;
	vector<vector<int>> fares = { { 4,1,10 },{3,5,24}, {5,6,2}, {3,1,41}, {5,1,24}, {4,6,50}, {2,4,66}, {2,3,22}, {1,6,25} };
	cout << solution(n, s, a, b, fares) << '\n';
	return 0;
}