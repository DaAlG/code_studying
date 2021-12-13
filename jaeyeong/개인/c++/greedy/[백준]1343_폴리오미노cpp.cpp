using namespace std;
#include <iostream>

int main() {
	bool done = false;
	string s, ans="";
	cin >> s;
	int size = s.size();
	
	for (int i = 0; i < size; i++) {
		done = false;
		//4Ä­ ºñ¾úÀ» ¶§
		for (int j = 0; j < 4; j++) {
			if (i + j >= size) break;
			if (s[i + j] == '.') break;
			if (j == 3) {
				ans += "AAAA";
				i += 3;
				done = true;
			}
		}
		if (done == true) continue;
		//2Ä­ ºñ¾úÀ» ¶§
		for (int j = 0; j < 2; j++) {
			if (i + j >= size) break;
			if (s[i + j] == '.') break;
			if (j == 1) {
				ans += "BB";
				i += 1;
				done = true;
			}
		}
		if (done == true) continue;
		if (s[i] == '.') {
			ans += '.';
		}
		else {
			cout << -1 << '\n';
			return 0;
		}
	}
	cout << ans << '\n';
	return 0;
}