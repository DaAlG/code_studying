#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		long long n;
		cin >> n;

		if (n % 2050 == 0) {
			int answer = 0;
			n /= 2050;
			while (n) {
				answer += n % 10;
				n /= 10;
			}
			cout << answer << '\n';
		}
		else {
			cout << -1 << '\n';
		}
	}

	return 0;
}