using namespace std;
#include <iostream>
#include <vector>
#include <string>

vector<string> alpha = { "dz=", "c=", "c-", "d-", "lj", "nj", "s=", "z=" };
string s;
int check(int idx) {
	string temp;
	if (idx < s.size() - 2) {
		temp = s.substr(idx, 3);
		if (temp == alpha[0]) return 2;
	}
	if (idx < s.size() - 1) {
		temp = s.substr(idx, 2);
		for (int i = 1; i < 8; i++)
			if (temp == alpha[i]) return 1;
	}
	return 0;
}
int main() {
	cin >> s;
	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		i += check(i);
		ans++;
	}
	cout << ans << '\n';
}