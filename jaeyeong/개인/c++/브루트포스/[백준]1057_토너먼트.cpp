using namespace std;
#include <iostream>

int n, jm, hs;
bool inRange(int idx, int k) {
	return idx <= jm && jm < (idx + k) && idx <= hs && hs < (idx + k);
}
int main() {
	cin >> n >> jm >> hs;
	int k = 2;
	int cnt = 0;
	int m = n;
	bool flag = false;
	if (n % 2 != 0) m--;


	if (n < jm || n < hs) {
		cnt = -1;
	}
	else {
		while (jm!=hs) {
			cnt++;
			jm = jm / 2 + jm % 2;//==jm-jm/2;
			hs = hs / 2 + hs % 2;
		}
	}
	cout << cnt << '\n';
}