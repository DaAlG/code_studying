using namespace std;
#include <iostream>

int n, m;

int main() {
	cin >> n >> m;
	if (n == 1) cout << 1;
	else if (n == 2) {
		if (m > 7) cout << 4;
		else cout << (m + 1) / 2;
	}
	else {
		if (m >= 7) cout << m - 2;
		else cout << min(m, 4);
	}
}