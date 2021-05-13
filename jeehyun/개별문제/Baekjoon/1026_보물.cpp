/*
 * 정렬
 * 1026 보물
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 0x7fffffff
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> a(n);
	vector<int> b(n);

	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());

	int answer = 0;
	for (int i = 0; i < n; i++) {
		answer += a[i] * b[i];
	}
	cout << answer;
	
	return 0;
}