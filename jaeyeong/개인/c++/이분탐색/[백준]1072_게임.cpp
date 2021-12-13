using namespace std;
#include <iostream>
#define MAX 1000000000;

int main() {
	double x, y;
	cin >> x >> y;
	int z = y * 100 / x; // z%

	if (z>= 99) {
		cout << "-1\n";
		return 0;
	}

	int bottom = 1, top = MAX;
	int answer = MAX;
	while (bottom <= top) {
		int mid = (bottom + top) / 2;
		int nz = (y + mid) * 100 / (x + mid);
		if (z < nz) {
			if (mid < answer) answer = mid;
			top = mid - 1;
		}
		else bottom = mid + 1;
	}
	cout << answer << '\n';
	return 0;
}