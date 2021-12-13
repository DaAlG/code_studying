using namespace std;
#include <iostream>

int main() {
	int n;
	int x, y;
	cin >> n;
	while (n--) {
		cin >> x >> y;
		int r = 1;
		for (int i = 0; i < y; i++) {
			r = r * x % 10;
		}
		if (r == 0) cout << "10\n";
		else cout << r << '\n';
	}
}