using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>

int n;
int op[4];

int solve(vector<int> v, vector<int> o) {
	int ans = v[0];
	for (int i = 1; i < n; i++) {
		switch (o[i-1]) {
		case 0:
			ans += v[i];
			break;
		case 1:
			ans -= v[i];
			break;
		case 2:
			ans *= v[i];
			break;
		case 3:
			ans /= v[i];
			break;
		}
	}
	return ans;
}

int main() {
	cin >> n;
	vector<int> v(n), o(n-1);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	for (int i = 0; i < 4; i++) {
		cin>>op[i];
	}
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < op[i]; j++) {
			o[cnt++] = i;
		}
	}

	int sum = solve(v, o);
	int minv = sum, maxv = sum;
	while (next_permutation(o.begin(), o.end())) {
		int temp = solve(v, o);
		if (minv > temp) minv = temp;
		if (temp > maxv) maxv = temp;
	}
	cout << maxv << '\n' << minv << '\n';
}