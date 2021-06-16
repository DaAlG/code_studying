/*
 * 수학
 * 10871 X보다 작은 수
 */

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, x, k;
	cin >> n >> x;

	while (n--) {
		cin >> k;
		if (k < x) {
			cout << k << ' ';
		}
	}

	return 0;
}