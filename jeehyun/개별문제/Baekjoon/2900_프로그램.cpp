/*
 * 누적 합
 * 2900 프로그램
 */

#include <iostream>
#define MAX 1000001
using namespace std;

int n, k;
long long a[MAX];
int cnt[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	
	for (int i = 0; i < k; i++) {
		int jump;
		cin >> jump;
		cnt[jump]++;
	}

	a[0] = k;
	for (int i = 1; i < n; i++) {
		if (cnt[i] != 0) {
			for (int j = i; j < n; j += i) {
				a[j] += cnt[i];
			}
		}
	}

	for (int i = 1; i < n; i++) {
		a[i] += a[i - 1];
	}

	int Q, left, right;
	cin >> Q;

	for (int i = 0; i < Q; i++) {
		cin >> left >> right;
		if (left == 0) cout << a[right] << '\n';
		else cout << a[right] - a[left - 1] << '\n';
	}

	return 0;
}