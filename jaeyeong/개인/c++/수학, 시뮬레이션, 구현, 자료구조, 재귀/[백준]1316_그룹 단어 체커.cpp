using namespace std;
#include <iostream>
#include <set>

int main() {
	char x;
	int tc, ans=0;
	cin >> tc;
	while (tc--) {
		string s;
		set<char> st;
		cin >> s;

		int idx = 0;
		while (idx < s.size()) {
			x = s[idx++];
			if (st.find(x) != st.end()) {
				idx--;
				break;
			}
			st.insert(x);
			while (x == s[idx] && idx<s.size()) {
				idx++;
			}
		}
		if (idx == s.size()) ans++;
	}
	cout << ans << '\n';
}