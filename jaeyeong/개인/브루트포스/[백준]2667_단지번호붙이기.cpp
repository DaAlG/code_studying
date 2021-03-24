using namespace std;
#include <iostream>
#include <queue>
#include <algorithm>

int board[25][25];
int visit[25][25];
int direction[4][2] = { {0,-1}, {0,1}, {1,0}, {-1,0} };
int n;

int bfs(int x, int y) {
	queue<pair<int, int>> q;
	int nx, ny, count=0;

	q.push(make_pair(x, y));
	board[x][y] = 0;
	visit[x][y] = 1;
	while (q.empty() != true) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			pair<int, int> v = q.front();
			q.pop();
			board[v.first][v.second] = 0;
			count++;
			for (int j = 0; j < 4; j++) {
				nx = v.first + direction[j][0];
				ny = v.second + direction[j][1];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (board[nx][ny] == 0 || visit[nx][ny]) continue;
				q.push(make_pair(nx, ny));
				visit[nx][ny] = 1;
			}
		}
		
	}
	return count;
}
int main() {
	vector<int> answer;
	char x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> x;
			board[i][j] = x - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 1)
				answer.push_back(bfs(i,j));
		}
	}
	
	sort(answer.begin(), answer.end());
	cout << answer.size() << '\n';
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << '\n';
}