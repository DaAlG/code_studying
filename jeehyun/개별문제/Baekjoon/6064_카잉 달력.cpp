/*
 * 브루트포스
 * 6064 카잉 달력
 */

#include <iostream>
using namespace std;

// 최대공약수
int gcd(int a, int b)
{
	if (b == 0) return a;
	else return gcd(b, a % b);
}

// 최소공배수
int lcm(int a, int b)
{
	int k = gcd(a, b);
	return k * (a / k) * (b / k);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, m, n, x, y;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> m >> n >> x >> y;

		int year;
		int max = lcm(m, n); // M과 N의 최소공배수가 카잉 달력의 마지막 해 (종말의 해)

		// 해를 M으로 나누었을 때 x이어야 하므로 x에 M을 계속 더한다
		for (year = x; year <= max; year += m) { 
			// 해당 년도의 y를 구한다
			int tmp = (year % n == 0) ? n : year % n;
			
			// 주어진 y를 만족하는 해이므로 출력
			if (tmp == y) {
				cout << year << '\n';
				break;
			}
		}

		// 마지막 해를 넘어갈 경우 -1 출력
		if (year > max)
			cout << -1 << '\n';
	}

	return 0;
}