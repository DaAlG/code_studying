using namespace std;
#include <iostream>
#include <algorithm>

int main() {
	string s, t;
	cin >> s >> t;
	int size_s = s.size();
	int size_t = t.size();
	while (size_t != size_s) {
		char c = t[size_t - 1];
		t.pop_back();
		if (c == 'B')
			reverse(t.begin(), t.end());
		size_t--;
	}
	if (t == s) cout << "1\n";
	else cout << "0\n";
}