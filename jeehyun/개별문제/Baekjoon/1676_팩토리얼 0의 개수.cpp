/* etc
 * 1676 팩토리얼 0의 개수
 * N!에서 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지 0의 개수 출력
 */

#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int ans = 0;
	// 뒷자리 0의 개수는 2와 5의 개수로 판단
	// 2를 약수로 가지고 있는 값이 훨씬 더 많기 때문에 5의 개수 체크
	// 1부터 n까지의 숫자에서 5^1 = 5의 배수, 5^2 = 25의 배수, ..., 5^k이 
	// n보다 작을 때까지 이들의 개수를 구한다
	// 이 개수는 n / 5^1 + n / 5^2 + ... 이런 방식으로 구할 수 있다
	for (int i = 5; i <= n; i *= 5)
		ans += n / i;
	cout << ans;

	return 0;
}