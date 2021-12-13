using namespace std;
#include <iostream>
#include <vector>

int n;
int input[21][21];
bool visit[21];
int ans = 987654321;

int ABS(int a, int b) {
	if (a < b) return b - a;
	else return a - b;
}


//k´Â a teamÀÇ ÆÀ¿ø ¼ö
void dfs(int c, int cnt) {
	if (cnt == n/2) {
		vector<int> a, b;
		int ascore = 0, bscore = 0;

		for (int i = 1; i <= n; i++) {
			if (!visit[i]) b.push_back(i);
			else a.push_back(i);
		}
		for (int i = 0; i < a.size(); i++) {
			for (int j = i + 1; j < a.size(); j++) {
				ascore += input[a[i]][a[j]] + input[a[j]][a[i]];
				bscore += input[b[i]][b[j]] + input[b[j]][b[i]];
			}
		}
		ans = min(ans, ABS(ascore,bscore));
		return;
	}
	for (int i = c+1; i <= n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			dfs(i, cnt+1);
			visit[i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> input[i][j];
		}
	}
	dfs(0, 0);
		
	cout << ans << '\n';
	return 0;
}