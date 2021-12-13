using namespace std;
#include <iostream>
#include <vector>

int n;//남극언어의 단어 수
int k;//가르칠 글자 수.
bool alphabet[26];
vector<string> v;
int answer = 0;

void input() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}
}

int ableNum() {
	int num = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			if (alphabet[v[i][j] - 'a'] == false)
				break;
			if (j == v[i].size() - 1)
				num++;
		}
	}
	return num;
}

void dfs(int cnt, int idx) {
	if (k == cnt) {
		int temp = ableNum();
		answer = answer > temp ? answer : temp;
		return;
	}

	for (int i = idx; i < 26; i++) {
		if (alphabet[i] == false) {
			alphabet[i] = true;
			dfs(cnt + 1, i + 1);
			alphabet[i] = false;
		}
	}
}

void solution() {
	input();
	if (k < 5) {
		cout << "0\n";
		return;
	}
	k -= 5;
	alphabet['a'-'a'] = true;
	alphabet['n' - 'a'] = true;
	alphabet['t' - 'a'] = true;
	alphabet['i' - 'a'] = true;
	alphabet['c' - 'a'] = true;
	dfs(0, 0);
	cout << answer << '\n';
}
int main() {

	solution();

}