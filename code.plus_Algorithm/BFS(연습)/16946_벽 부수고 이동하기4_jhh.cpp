/*
0은 빈칸 1은 이동할 수 없는 곳
두 칸이 변을 공유할 때, 인접한다고 한다.
각각의 벽을 빈 칸으로 바꾸고, 그 위치에서 이동할 수 있는 칸의개수 %10을 구해보자

DFS. BFS로 구할 수 있음
시간복잡도 = O(NM)
총 시간 복잡도 = O(NM^2)

매번 바꾸는 것으로는 풀 수 없는 문제임

=> 하나의 빈 칸을 벽으로 바꾸는 것이 아니라 하나의 벽을 빈칸으로 바꾸었을 때 

이동할 수 있는 빈 칸 모두 그룹 짓는다 : 묶어버림
몇 개의 칸을 이루어져 있는지 계산
각각의 벽을 빈칸으로 바꾸었을 때 그 칸에서 이동할 수 있는 칸의 개수를 세어보는 것
그룹의 크기를 다 더하고 빈칸으로 바꾼 것 더하면 총 갯수임
겹치는 그룹은 모두 계산할 필요 없음
=> 하나의 벽을 빈칸으로 바꿀 때 마다 다시 상하좌우의 정보만 계산해주면 됨 => O(NM)

*/
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<tuple>

using namespace std;
int n, m;
int a[1000][1000];
bool check[1000][1000];
int group[1000][1000];
vector<int> group_size;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void bfs(int sx, int sy) {
	int g = group_size.size();
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));
	check[sx][sy] = true;
	group[sx][sy] = g;
	int cnt = 1;
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front(); q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if(0<nx&&nx<n&&0<=ny&&ny<m)
				if (a[nx][ny] == 0 && check[nx][ny] == false) {
					q.push(make_pair(nx, ny));
					check[nx][ny] = true;
					group[nx][ny] = g;//group번호 생성
					cnt += 1;
				}
		}
	}
	group_size.push_back(cnt);
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			a[i][j] = s[j] - '0';
			check[i][j] = false;
			group[i][j] = -1;
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] == 0 && check[i][j] == false)
				bfs(i, j);// 방문 한 적이 없을 때
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0)
				cout << 0;
			else {
				set<int> near; // 같은 그룹 포함시키지 않기 위해 set 사용
				for (int k = 0; k < 4; k++) {
					int x = i + dx[k];
					int y = j + dy[k];
					if (0 <= x && x < n && 0 <= y && y < m)
						if (a[x][y] == 0)
							near.insert(group[x][y]);//set은 같은 값 들어가지 않음
				}
				int ans = 1;
				for (int g : near)
					ans += group_size[g];
				cout << ans % 10;
			}

		}
		cout << '\n';
	}
	return 0;
}