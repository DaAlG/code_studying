/* etc
 * 2004 조합 0의 개수
 * nCm의 끝자리 0의 개수 출력
 */

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// nCm = n! / m!(n-m)!
	int n, m;
	cin >> n >> m;

	int two = 0;
	// n!, m!, (n-m)!에서의 2와 5의 개수를 구한다
	// n!의 개수에서 m!과 (n-m)!의 개수를 빼야한다
	// 조합을 구할 때는 나눗셈을 포함하므로 5의 개수만 세면 안된다
	for (long long i = 2; i <= n; i *= 2)
		two += n / i;

	for (long long i = 2; i <= m; i *= 2)
		two -= m / i;

	for (long long i = 2; i <= n - m; i *= 2)
		two -= (n - m) / i;
	

	int five = 0;
	// 인수분해한 결과에서 5의 개수를 구한다
	// 1부터 n까지의 숫자에서 5^1 = 5의 배수, 5^2 = 25의 배수, ..., 5^k이 
	// n보다 작을 때까지 이들의 개수를 구한다
	// 이 개수는 n / 5^1 + n / 5^2 + ... 이런 방식으로 구할 수 있다
	for (long long i = 5; i <= n; i *= 5)
		five += n / i;

	for (long long i = 5; i <= n; i *= 5)
		five -= m / i;

	for (long long i = 5; i <= n - m; i *= 5)
		five -= (n - m) / i;

	cout << min(two, five);
	return 0;
}