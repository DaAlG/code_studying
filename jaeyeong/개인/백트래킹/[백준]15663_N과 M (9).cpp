using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

int n, m;
vector<int> v;
int arr[9];
bool visit[9];
set<string> st;

void comb(int cnt) {
	if (cnt == m) {
		string s = "";
		for (int i = 0; i < m; i++)
			s += to_string(arr[i]) + ' ';
		if (st.find(s) == st.end()) {
			st.insert(s);
			cout << s << '\n';
		}
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			arr[cnt] = v[i];
			comb(cnt + 1);
			visit[i] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	bool simpleV = true;
	for (int i = 1; i < n; i++) {
		if (v[i - 1] != v[i]) {
			simpleV = false;
			break;
		}
	}
	if (simpleV == false) {
		sort(v.begin(), v.end());
		comb(0);
	}
	else {
		for (int i = 0; i < m; i++)
			cout << v[i] << ' ';
	}
}