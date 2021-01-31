/* etc
 * 1929 소수 구하기
 * M 이상 N 이하의 소수를 모두 출력
 */

#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int min, max;
	cin >> min >> max;

	bool *prime = new bool[max + 1];
	fill_n(prime, max + 1, 1);
	prime[0] =  prime[1] = false;

	// 에라토스테네스의 체 활용
	// 2부터 시작해서 특정 수의 배수에 해당사는 수를 모두 지운다
	// 지울 때 자시자신은 지우지 않고 이미 지워진 수는 건너뛴다
	for (int i = 2; i <= sqrt(max); i++) {
		if (prime[i]) {
			// 지워진 숫자가 아니라면, 그 배수부터 출발하여 가능한 모든 숫자 지우기
			for (int j = i * 2; j <= max; j += i)
				prime[j] = false;
		}
	}

	// min부터 시작하여 남아있는 수 모두 출력
	for (int i = min; i <= max; i++)
		if (prime[i])
			cout << i << "\n";

	return 0;
}