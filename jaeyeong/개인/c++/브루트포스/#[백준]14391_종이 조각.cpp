using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

int n, m;
int paper[4][4];
bool check[4][4];
int xy[4][4]; //0:가로로 합, 1:세로로 합
vector<int> ans;

int dfs(int x, int y, int sum) {
	check[x][y] = true;
	if (xy[x][y] == 0) { //가로로 확인하는 경우
		if (y + 1 < m && xy[x][y] == xy[x][y + 1] && !check[x][y + 1])
			sum = dfs(x, y + 1, (sum * 10) + paper[x][y]); // 가로로 종이를 이어붙여 넘김
		else
			return sum * 10 + paper[x][y]; // 마지막 수 처리
	}
	if (xy[x][y] == 1) {
		if (x + 1 < n && xy[x][y] == xy[x + 1][y] && !check[x + 1][y])
			sum = dfs(x + 1, y, (sum * 10) + paper[x][y]); // 세로로 종이를 이어붙여 넘김
		else
			return sum * 10 + paper[x][y]; // 마지막 수 처리
	}
	return sum;
}

int makeSum() {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!check[i][j])
				sum += dfs(i, j, 0);
		}
	}
	return sum;
}
void go(int index) {
	if (index == m * n) {
		memset(check, false, sizeof(check));
		ans.push_back(makeSum()); //정답 후보
		return;
	}
	xy[index / m][index % m] = 1; // 1을 넣는 경우
	go(index + 1);
	xy[index / m][index % m] = 0; // 0을 넣는 경우
	go(index + 1);
}
int main() {
	char x;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> x;
			paper[i][j] = x - '0';
		}
	}
	go(0);

	int answer = -1;
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] > answer) answer = ans[i];
	}
	cout << answer << '\n';
}