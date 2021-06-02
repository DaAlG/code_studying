/*
 * 구현
 * 5597 과제 안 내신 분..?
 */

#include <iostream>
using namespace std;

bool submit[31];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;

	for (int i = 0; i < 28; i++) {
		cin >> n;
		submit[n] = true;
	}

	for (int i = 1; i <= 30; i++) {
		if (!submit[i]) {
			cout << i << '\n';
		}
	}

	return 0;
}