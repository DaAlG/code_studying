/*
 * 누적 합
 * 11659 구간 합 구하기 4
 */

#include <iostream>
#define MAX 100001
using namespace std;

int arr[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}

	for (int t = 0; t < m; t++) {
		int s, e;
		cin >> s >> e;
		cout << arr[e] - arr[s - 1] << '\n';
	}

	return 0;
}