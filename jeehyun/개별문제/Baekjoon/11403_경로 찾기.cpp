/*
 * 그래프
 * 11403 경로 찾기
 */

#include <iostream>
#define MAX 101
using namespace std;

int graph[MAX][MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}
	
	for (int k = 0; k < n; k++) { // 거쳐가는 노드
		for (int i = 0; i < n; i++) { // 출발 노드
			for (int j = 0; j < n; j++) { // 도착 노드
				// 경로가 존재한다
				if (graph[i][k] + graph[k][j] >= 2)
					graph[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << graph[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}