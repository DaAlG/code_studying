/*
100개의 칸으로 나누어져 있는 게임. 1에서 100으로 가야 한다.

주사위를 굴려 나온 수 만큼 이동할 수 있으며,
도착한 칸이 사다리인 경우에는 사다리를 타고 더 큰 칸으로
뱀인 경우에는 더 작은 번호의 칸으로 이동한다.

사다리와 뱀 둘 다인 경우는 없다.

주사위에 나온 수를 정할 수 있을 때, 최소 몇번 굴려야하는지 구하는 문제

시작점-1 도착점-100
어떤 칸 x 에서 1,2,3,4...가 나오는 경우

*/
#include<iostream>
#include<algorithm>
#include<queue>
#define next _next
//next[x]=y : x->y로 이동했을 때 그 다음 칸의 정보를 저장
//뱀이나 사다리인 경우 next[x]=y
//일반 칸인 경우 next[x]=x
using namespace std;
int dist[101];
int next[101];//일반 칸
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= 100; i++) {
		next[i] = i;//사다리나 뱀을 사용한 경우
		dist[i] = -1;//거리 -1로 초기화
	}
	while (n--) {
		int x, y;
		cin >> x >> y;
		next[x] = y;//사다리
	}
	while (m--) {
		int x, y;
		cin >> x >> y;
		next[x] = y;
	}//뱀
	dist[1] = 0;
	queue<int> q;
	q.push(1);//시작점에 대한 처리
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = 1; i <= 6; i++) {
			int y = x + i;
			if (y > 100) continue;
			y = next[y];

			//BFS
			if (dist[y] == -1) {
				dist[y] = dist[x] + 1;
				q.push(y);
			}
		}
	}
	cout << dist[100] << '\n';//100번 칸 까지 가는데 필요한 칸의 최소
	return 0;
}