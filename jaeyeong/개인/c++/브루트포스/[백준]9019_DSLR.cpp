using namespace std;
#include <iostream>
#include <queue>
#include <stack>
#include <cstring>


int dis[100010], from[100010];
char how[100010];
bool check[100010];

void print(int n, int m) {
	if (n == m) return;
	print(n, from[m]);
	cout << how[m];
}

void solve(int a) {
	queue<int> q;
	dis[a] = 0;
	from[a] = -1;
	check[a] = true;
	q.push(a);
	while (!q.empty()) {
		int c = q.front();
		q.pop();
		int next;
		char hn;
		for (int i = 0; i < 4; i++) {
			next = c;
			switch (i) {
			case 0:
				next = (next * 2) % 10000;
				hn = 'D';
				break;
			case 1:
				next -= 1;
				if (next == -1) next = 9999;
				hn = 'S';
				break;
			case 2:
				next = (c % 1000) * 10 + c / 1000;
				hn = 'L';
				break;
			case 3:
				next = (c / 10) + (c % 10) * 1000;
				hn = 'R';
				break;
			}
			if (check[next]==false) {
				dis[next] = dis[c] + 1;
				from[next] = c;
				how[next] = hn;
				check[next] = true;
				q.push(next);
			}
		}
	}
}
int main() {
	int a, b;
	int test;
	cin >> test;
	while (test--) {
		memset(dis, 0, sizeof(dis));
		memset(from, 0, sizeof(from));
		memset(how, 0, sizeof(how));
		memset(check, false, sizeof(check));
		cin >> a >> b;
		solve(a);
		print(a, b);
		cout << '\n';
	}
}