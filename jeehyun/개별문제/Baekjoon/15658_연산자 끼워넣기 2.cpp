/* 브루트포스
 * 15658 연산자 끼워넣기 2
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000000000
using namespace std;

int n;
int arr[11];
int maximum = -MAX;
int minimum = MAX;

void calc(int index, int cur, int plus, int minus, int mult, int div)
{
	if (index == n) {
		maximum = max(maximum, cur);
		minimum = min(minimum, cur);
		return;
	}

	vector<pair<int, int>> res;

	if (plus > 0)
		calc(index + 1, cur + arr[index], plus - 1, minus, mult, div);
	if (minus > 0)
		calc(index + 1, cur - arr[index], plus, minus - 1, mult, div);
	if (mult > 0)
		calc(index + 1, cur * arr[index], plus, minus, mult - 1, div);
	if (div > 0)
		calc(index + 1, cur / arr[index], plus, minus, mult, div - 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int plus, minus, mult, div;
	cin >> plus >> minus >> mult >> div;

	calc(1, arr[0], plus, minus, mult, div);
	cout << maximum << "\n";
	cout << minimum << "\n";

	return 0;
}