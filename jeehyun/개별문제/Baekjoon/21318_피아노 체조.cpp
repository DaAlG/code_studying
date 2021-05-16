/*
 * 누적 합
 * 21318 피아노 체조
 */

#include <iostream>
#define MAX 100001
using namespace std;

int level[MAX];
int d[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, Q, x, y;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> level[i];
	}

	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1];
		if (level[i - 1] > level[i])
			d[i]++;
	}

	cin >> Q;
	for (int q = 0; q < Q; q++) {
		cin >> x >> y;
		cout << d[y] - d[x] << '\n';
	}

	return 0;
}