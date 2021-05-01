#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int r, b, d;
		cin >> r >> b >> d;

		int tmpmin = min(r, b);
		int tmpmax = max(r, b);

		if (ceil((double)tmpmax/ (d + 1)) <= tmpmin)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}