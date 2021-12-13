using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

int n, m;
int arr[8];
vector<int> v;
set<string> st;

void comb(int idx,int cnt) {
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
	for (int i = idx; i < n; i++) {
		arr[cnt] = v[i];
		comb(idx, cnt + 1);
	}
}
int main() {
	cin >> n >> m;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	comb(0, 0);
}