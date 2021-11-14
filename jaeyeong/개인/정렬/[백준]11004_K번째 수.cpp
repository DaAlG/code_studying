using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 5000000

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	vector<int> v;
	cin >> n >> k;
	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	cout << v[k-1] << '\n';
}