using namespace std;
#include <iostream>
#include <queue>
#include <tuple>
#include <set>

int n, m;
int board[1000][1000], groupBoard[1000][1000];
int answer[1000][1000];
int groupRes[1000000];
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

void makeGroup(int sx, int sy, int cnt) {
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));
	groupBoard[sx][sy] = cnt;
	int res = 0;
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		res++;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx < 0 || n <= nx) continue;
			if (ny < 0 || m <= ny) continue;
			if (board[nx][ny] == 1 || groupBoard[nx][ny]!=0) continue;
			groupBoard[nx][ny] = cnt;
			q.push(make_pair(nx, ny));
		}
	}
	groupRes[cnt] = res;
	return;
}

int main() {
	char x;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> x;
			board[i][j] = x - '0';
		}
	}
	int gn = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j]==0 && groupBoard[i][j] == 0)
				makeGroup(i, j,gn++);
		}
	}
	set<int> st;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0) continue;
			else {
				for (int k = 0; k < 4; k++) {
					int nx = i + dir[k][0];
					int ny = j + dir[k][1];
					if (nx < 0 || n <= nx) continue;
					if (ny < 0 || m <= ny) continue;
					st.insert(groupBoard[nx][ny]);
				}
				int sum = 1;
				set<int>::iterator iter;
				for (iter = st.begin(); iter!= st.end(); iter++)
					sum += groupRes[*iter];
				answer[i][j] = sum%10;
				st.clear();
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << answer[i][j];
		}
		cout << '\n';
	}
}