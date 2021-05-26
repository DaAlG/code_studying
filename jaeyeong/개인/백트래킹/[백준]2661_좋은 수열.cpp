using namespace std;
#include <iostream>
#include <string>

int n;
string arr;
bool done = false;

bool isGood(int m) {
	for (int i = m; m / 2 < i; i--) {
		string s1 = "", s2;
		for (int j = m; j >= i; j--)
			s1 = arr[j] + s1;

		int from = 2*i-m-1;
		s2 = arr.substr(from, m-i+1);
		if (s1==s2) return false;
	}
	return true;
}
void solve(int cnt) {
	if (cnt == n) {
		done = true;
		cout << arr << '\n';
		return;
	}

	for (int i = 1; i <= 3; i++) {
		arr[cnt] = i+'0';
		if (!isGood(cnt)) continue;
		solve(cnt + 1);
		if (done == true) return;
	}
}
int main() {
	cin >> n;
	arr.resize(n);
	solve(0);
	return 0;
}