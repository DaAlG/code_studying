using namespace std;
#include <iostream>
#include <cmath>

int n, r, c;
int dx[4] = { 0,0,1,1 };
int dy[4] = { 0,1,0,1 };
int ans;
bool flag = false;

void solve(int x, int y, int size) {
	if (flag == true) return;
	if (size ==2) {
		flag = true;
		if (x == r && y == c) ans += 0;
		else if (x == r && y + 1 == c) ans += 1;
		else if (x + 1 == r && y == c) ans += 2;
		else  if (x + 1 == r && y + 1 == c) ans += 3;
		else {
			ans += 4;
			flag = false;
		}
		return;
	}
	
	if (x <= r && r < x + size && y <= c && c < y + size) {
		int half = size / 2;
		solve(x, y, half);
		solve(x, y + half, half);
		solve(x + half, y, half);
		solve(x + half, y + half, half);
	}
	else
		ans += pow(size, 2);
}
int main() {
	cin >> n >> r >> c;
	solve(0, 0, pow(2,n));
	cout << ans << '\n';
}