using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

//nCm
int n, m;
vector<int> v;
int visit[9], arr[9];
set<string> st;

void comb(int cnt) {
	if (cnt == m) {
		string s;
		for (int i = 0; i < m; i++) {
			s += to_string(arr[i]) + ' ';
		}
		if (st.find(s) == st.end()) {
			st.insert(s);
			cout << s << '\n';
		}
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			visit[i] = 1;
			arr[cnt] = v[i];
			comb(cnt + 1);
			visit[i] = 0;
		}
	}
}
int main() {
	cin >> n >> m;
	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	comb(0);
}