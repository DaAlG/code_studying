using namespace std;
#include <iostream>

int main() {
	int t, a, b, c;
	cin >> t;
	if (t % 10 != 0) {
		cout << "-1\n";
		return 0;
	}
	a = t / 300;
	if (a != 0)
		t = t % 300;
	b = t / 60;
	if (b != 0)
		t = t % 60;
	c = t / 10;
	cout << a << ' ' << b << ' ' << c << '\n';
	return 0;
}