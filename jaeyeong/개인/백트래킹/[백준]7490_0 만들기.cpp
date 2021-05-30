using namespace std;
#include <iostream>
#include <string>
#include <vector>

int tc, n;
int arr[10];
char sign[3] = { '+',' ','-' };

void solve(int sum, int sign, int num, int cnt, string s) {
	if (cnt == n+1) {
		sum += num * sign;
		if (sum == 0) cout << s << '\n';
		return;
	}
	solve(sum, sign, num * 10 + arr[cnt], cnt + 1, s + ' ' + to_string(arr[cnt]));
	solve(sum + sign*num, 1, arr[cnt],cnt + 1, s + '+' + to_string(arr[cnt]));
	solve(sum + sign*num, -1, arr[cnt],cnt + 1, s + '-' + to_string(arr[cnt]));
}
int main() {
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			arr[i] = i;
		string s = "";
		s += to_string(arr[1]);
		solve(0, 1, arr[1], 2, s);
		cout << '\n';
	}
}