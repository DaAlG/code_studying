using namespace std;
#include <iostream>

int n;
int wine[10001], drink[10001][3];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> wine[i];

	drink[1][0] = 0;
	drink[1][1] = wine[1];
	drink[1][2] = wine[1];

	drink[2][0] = wine[1] + wine[2];
	drink[2][1] = wine[2];
	drink[2][2] = drink[2][0];

	if (n >= 3) {
		for (int i = 3; i <= n; i++) {
			drink[i][0] = drink[i - 1][1] + wine[i];
			drink[i][1] = (drink[i - 2][2] > drink[i - 3][2] ? drink[i - 2][2] : drink[i - 3][2]) + wine[i];
			drink[i][2] = drink[i][0] > drink[i][1] ? drink[i][0] : drink[i][1];
		}
	}

	int bigger = drink[n - 1][2] > drink[n][2] ? drink[n - 1][2] : drink[n][2];
	if (bigger < drink[n - 2][2]) bigger = drink[n - 2][2];
	cout << bigger << '\n';
}