// SW Expert Academy
// S/W 문제해결 기본 4일차 - 1217 거듭 제곱

#include <iostream>

using namespace std;

int exp(int n, int m, int res) 
{
	if (m == 0)
		return res;
		
	exp(n, --m, res * n);
}

int main()
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> test_case;

		int n, m;
		cin >> n >> m;
		int ans = exp(n, m, 1);

		cout << "#" << test_case << " " << ans << endl;
	}

	return 0;
}