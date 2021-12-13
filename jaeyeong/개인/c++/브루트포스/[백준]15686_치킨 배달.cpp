using namespace std;
#include <iostream>
#include <map>

int n, m, ans=0x3f3f3f3f;
//input[51][51]로 할땐 틀렸다고 나왔다,, 왜지? ㅜ
int input[200][200], dis[200][200], arr[200], c, h;
bool visit[200];
map<int, pair<int, int>> chicken, home;


int ABS(int a, int b) {
	if (a < b)
		return b - a;
	else return a - b;
}


void setDis() {
	for (int i = 0; i < c; i++) {
		int cx = chicken[i].first;
		int cy = chicken[i].second;
		for (int j = 0; j < h; j++) {
			int hx = home[j].first;
			int hy = home[j].second;
			dis[i][j] = ABS(cx, hx) + ABS(cy, hy);
		}
	}
}

int getDis() {
	int sum=0, minValue;
	for (int j = 0; j < h; j++) {
		minValue = 0x3f3f3f3f;
		for (int i = 1; i <= m; i++) {
			minValue = min(minValue, dis[arr[i] - 1][j]);
		}
		sum += minValue;
	}
	return sum;
}

//aCb
void comb(int cnt) {
	if (cnt == m) {
		int curDis = getDis();
		if (curDis < ans) ans = curDis;
		return;
	}
	for (int i = arr[cnt] + 1; i <= c; i++) {
		if (!visit[i]) {
			visit[i] = true;
			arr[cnt + 1] = i;
			comb(cnt + 1);
			visit[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> input[i][j];
			if (input[i][j] == 2)
				chicken[c++] = make_pair(i, j);
			if (input[i][j] == 1)
				home[h++] = make_pair(i, j);
		}
	}

	setDis();
	comb(0);
	cout << ans << '\n';
}