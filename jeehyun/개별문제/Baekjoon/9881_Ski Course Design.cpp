/*
 * 브루트포스?
 * 9881 Ski Course Design 
 */

#include <iostream>
#include <algorithm>
#define MAX 1001
#define INF 0x7fffffff
using namespace std;

int hills[MAX];

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> hills[i];

	int answer = INF;

	// 0 ~ 17, 1 ~ 18, ..., 83 ~ 100으로 17 차이를 가지는 모든 범위를 만들어서 언덕을 바꿔본다
	for (int i = 0; i <= 100 - 17; i++) {
		int tmp = 0;
		for (int j = 0; j < n; j++) {
			if (hills[j] < i)
				tmp += (i - hills[j]) * (i - hills[j]);
			if (hills[j] > i + 17)
				tmp += (hills[j] - i - 17) * (hills[j] - i - 17);
		}
		answer = min(answer, tmp);
	}
	cout << answer;

	return 0;
}