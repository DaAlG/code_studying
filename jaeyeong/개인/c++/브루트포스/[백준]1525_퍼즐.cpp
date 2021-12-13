//visit를 map으로 구현
//처음엔 스트링을 set인 visit에 넣고 있는지 확인하려 했는데 너무 오래걸린다.
//bfs 기본 문제도 보통 visit에 거리 넣었잖아 그치?
//또한 0을 9로 해야 string>int로 변환 후 비교할때 누락이 안됨.
using namespace std;
#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <tuple>

int direction[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int target = 123456789;


int bfs(int sx, int sy,int start) {
	bool done = false;
	map<int, int> visit;
	queue<int> q;
	q.push(start);
	visit[start] = 0;

	while (!q.empty()) {
		int cur = q.front();
		string s = to_string(cur);
		q.pop();

		if (cur == target) {
			done = true;
			break;
		}
		int z = s.find('9');
		int x = z / 3;
		int y = z % 3;

		for (int i = 0; i < 4; i++) {
			int nx = x + direction[i][0];
			int ny = y + direction[i][1];
			if (nx < 0 || 2 < nx || ny < 0 || 2 < ny) continue;
			string temp = s;
			swap(temp[x * 3 + y], temp[nx * 3 + ny]);
			int next = stoi(temp);
			if (!visit.count(next)) {
				visit[next] = visit[cur] + 1;
				q.push(next);
			}
		}
	}
	if (done == true) return visit[target];
	else return -1;
}
int main() {
	int sx, sy, x, start=0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> x;
			if (x == 0) {
				sx = i;
				sy = j;
				x = 9;
			}
			start = start * 10 + x;

		}
	}
	cout << bfs(sx, sy, start) << '\n';
}