/*
 * 수학
 * 1016 제곱 ㄴㄴ 수
 */

#include <iostream>
#define MAX 1000001
using namespace std;

bool number[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long min, max;
	cin >> min >> max;

	for (long long i = 2; i * i <= max; i++) {
		// 처음으로 i * i로 나누어떨어지는 수를 찾아야 한다
		long long n = min / (i * i); 

		// min을 i * i로 나눴을 때 나머지가 있는 경우
		// n * i * i가 min보다 작은 수가 되므로 n++ 해준다
		if (min % (i * i)) n++;

		while (n * i * i <= max) {
			// 제곱수
			number[n * i * i - min] = true;
			n++;
		}
	}

	int answer = 0;
	for (int i = 0; i <= max - min; i++) {
		if (!number[i]) // 제곱 ㄴㄴ 수
			answer++;
	}
	cout << answer;

	return 0;
}