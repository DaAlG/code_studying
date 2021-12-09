using namespace std;
#include <iostream>
#include <vector>

int n, k;
vector<string> words;
bool alphabet[26];
int answer = 0;
int ableNum() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int ws = words[i].size();
		for (int j = 0; j < ws; j++) {
			if (!alphabet[words[i][j] - 'a']) break;
			if (j == ws - 1) cnt++;
		}
	}
	return cnt;
}
void dfs(int idx, int cnt) {
	if (cnt == k) {
		int temp = ableNum();
		answer = answer > temp ? answer : temp;
		return;
	}
	for (int i = idx; i < 26; i++) {
		if (alphabet[i] == false) {
			alphabet[i] = true;
			dfs(i + 1, cnt + 1);
			alphabet[i] = false;
		}
	}
}
int solution() {
	if (k < 5) return 0;
	alphabet['a' - 'a'] = true;
	alphabet['n' - 'a'] = true;
	alphabet['t' - 'a'] = true;
	alphabet['i' - 'a'] = true;
	alphabet['c' - 'a'] = true;
	dfs(0, 5);
	return answer;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	words.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> words[i];
	}
	int answer = solution();
	cout << answer << '\n';
}