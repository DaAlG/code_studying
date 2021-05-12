/*
 * 정렬
 * 10867 중복 빼고 정렬하기
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
	for (int i = 0; i < n; i++) 
		cin >> a[i];

	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());

	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << ' ';
	}

	return 0;
}