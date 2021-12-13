#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	int test, n;
	int a, b, result=1;
	vector<pair<int, int>> v;

	cin >> test;
	for (int t = 0; t < test; t++) {
		v.clear();
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			v.push_back(pair<int, int>(a, b));
		}
		sort(v.begin(), v.end());

		a = v[0].second;
		for (int i = 1; i < n; i++) {
			if (v[i].second < a) {
				result++;
				if (v[i].second == 1)
					break;
				a = v[i].second;
			}
		}
		cout << result << '\n';
		result = 1;
	}
	
}