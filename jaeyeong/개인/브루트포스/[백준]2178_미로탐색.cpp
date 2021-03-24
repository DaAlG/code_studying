using namespace std;
#include <iostream>
#include <queue>

int board[101][101];
int visit[101][101];

int bfs(int n, int m) {
	pair<int, int> v;
	queue<pair<int, int>> q;
	int togoX, togoY, count=0;
	int direction[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} }; //µ¿¼­³²ºÏ

	q.push(make_pair(1, 1));
	visit[1][1] = 1;
	while(q.empty() != true) {
		int size = q.size();

		for (int i = 0; i < size; i++) {
			v = q.front();
			q.pop();
			if (v.first == n && v.second == m)
				return count+1;

			for (int j = 0; j < 4; j++) {
				togoX = v.first + direction[j][0];
				togoY = v.second + direction[j][1];
				if (togoX <= 0 || togoX > n || togoY <= 0 || togoY > m)
					continue;
				if (board[togoX][togoY] == 0)
					continue;
				if (visit[togoX][togoY] == 1)
					continue;
				visit[togoX][togoY] = 1;
				q.push(make_pair(togoX, togoY));
			}
		}
		count++;
	}
}

int main() {
	int n, m;
	char x;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> x;
			board[i][j] = x - '0';
		}
	}
	cout << bfs(n,m);
}