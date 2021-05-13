#include <iostream>
#include <map>
using namespace std;

int main()
{
	int T, n;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> n;

		map<int, int> a; // (ai - i)가 나온 횟수
		long long answer = 0;

		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;

			x -= i; // ai - i = aj - j
			answer += a[x];
			a[x]++;
		}
		cout << answer << '\n';
	}

	return 0;
}