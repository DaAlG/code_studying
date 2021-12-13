using namespace std;
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int n, m, nn=1;
vector<int> mp[1000001];


void solution() {

	for (int i = 10; i <= n; i++) {
		if (i % 10 == 0) nn++;

		int sum = 0;
		int j = i;
		while (j) {
			sum += j % 10;
			j = j / 10;
		}
		mp[sum].push_back(i);
	}
}
int main() {
	cin >> n;
	if (n >= 10) {
		solution();
		for (int i = 10; i <= n; i++) {
			int k = n - i;
			if (mp[k].empty() == true) continue;
			for (int j = 0; j < mp[k].size(); j++) {
				if (i == mp[k][j]) {
					cout << i << '\n';
					return 0;
				}
			}
		}
	}
	cout << 0 << '\n';
}