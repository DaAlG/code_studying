using namespace std;
#include <iostream>

int solve(char x) {
	if ('A' <= x && x <= 'C') return 3;
	else if ('D' <= x && x <= 'F') return 4;
	else if ('G' <= x && x <= 'I') return 5;
	else if ('J' <= x && x <= 'L') return 6;
	else if ('M' <= x && x <= 'O') return 7;
	else if ('P' <= x && x <= 'S') return 8;
	else if ('T' <= x && x <= 'V') return 9;
	else if ('W' <= x && x <= 'Z') return 10;
	return 10 * 2;
}
int main() {
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < s.size(); i++)
		ans += solve(s[i]);
	cout << ans << '\n';
}