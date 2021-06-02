/*
 * 수학
 * 5618 공약수
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int gcd(int a, int b)
{
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int a, b, c, tmp;
	
	if (n == 2) {
		cin >> a >> b;
		tmp = gcd(a, b);
	}
	else {
		cin >> a >> b >> c;
		tmp = gcd(gcd(a, b), c);
	}

	vector<int> cd;
	for (int i = 1; i <= sqrt(tmp); i++) {
		if (tmp % i == 0) {
			cd.push_back(i);
			cd.push_back(tmp / i);
		}
	}

	sort(cd.begin(), cd.end());
	cd.erase(unique(cd.begin(), cd.end()), cd.end());

	for (int i = 0; i < cd.size(); i++) {
		cout << cd[i] << '\n';
	}
	return 0;
}