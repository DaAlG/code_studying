#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n, k;
	string s;
	vector<char> st;

	cin >> n >> k;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		while (!st.empty() && st.back() < s[i] && k > 0) {
			st.pop_back();
			k--;
		};
		st.push_back(s[i]);
	}
	while (k--) {
		st.pop_back();
	}

	for(int i=0;i<st.size();i++){
		cout<<st[i];
	}
	return 0;
}