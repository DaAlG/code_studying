/* 
 * 그리디
 * 14916 거스름돈
 */

#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int answer = 0;

	while (n >= 5) {
		if (n % 5 == 0 || n % 2 == 1) {
			answer++;
			n -= 5;
		}
		else if (n % 2 == 0) {
			answer++;
			n -= 2;
		}
	}

	if (n % 2 == 0) {
		answer += n / 2;
	}

	if (answer != 0)
		cout << answer;
	else
		cout << -1;
	

	return 0;
}