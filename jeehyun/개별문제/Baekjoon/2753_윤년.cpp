/*
 * 수학
 * 2753 윤년
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

	bool check = false;
	if (n % 4 == 0 && n % 100 != 0)
		check = true;
	else if (n % 400 == 0)
		check = true;

	if (check)
		cout << 1;
	else
		cout << 0;

	return 0;
}