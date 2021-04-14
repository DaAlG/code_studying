using namespace std;
#include <iostream>
#include <algorithm>
#include <string>
#include <set>

int n, ans = 0x3f3f3f3f;
string goal;
pair<string, int> price[16];
int alpha[16][26] = { 0 };
int selected[16];
bool visit[16];

bool compare(int a, int b) {
	return price[a].second < price[b].second;
}

int getPrice(int k) {
	int temp[16] = { 0 }, t_alpha[16][26];
	int res = 0;

	for (int i = 1; i <= k; i++)
		temp[i] = selected[i];
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 26; j++) {
			t_alpha[i][j] = alpha[i][j];
		}
	}

	if (k != 1)
		sort(temp + 1, temp + k, compare);
	for (int i = 0; i < goal.size(); i++) {
		for (int j = 1; j <= k; j++) {
			if (price[temp[j]-1].first.find(goal[i]) != string::npos) {
				if (t_alpha[temp[j]-1][goal[i] - 'A'] > 0) {
					t_alpha[temp[j]-1][goal[i] - 'A']--;
					break;
				}
			}
			if (j == k)
				return -1;
		}
	}
	for (int i = 1; i <= k; i++)
		res += price[selected[i]-1].second;
	return res;
}
//nCk
void comb(int k, int cnt) {
	if (k == cnt) {
		int res = getPrice(k);
		if (res < ans && res != -1)
			ans = res;
		return;
	}
	for (int i = selected[cnt]+1; i <= n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			selected[cnt + 1] = i;
			comb(k, cnt + 1);
			visit[i] = false;
		}
	}
}

void setAlpha() {
	for (int i = 0; i < n; i++) {
		string s = price[i].first;
		for (int j = 0; j < s.size(); j++) {
			alpha[i][s[j]-'A'] ++;
		}
	}
}

int main() {
	string x;
	int y;
	cin >> goal;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> y >> x;
		price[i] = make_pair(x, y);
	}

	setAlpha();

	for (int i = 1; i <= n; i++)
		comb(i, 0);
	if (ans == 0x3f3f3f3f)
		ans = -1;
	cout << ans << '\n';
}