#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int n, x;
		cin >> n >> x;

		vector<int> w(n);
		int sum = 0;

		for (int i = 0; i < n; i++) {
			cin >> w[i];
			sum += w[i];
		}

		// 총합이 x일 경우 순서를 바꾸더라도 폭발을 피할 수 없다
		if (sum == x) {
			cout << "NO\n";
			continue;
		}

		// 총합이 x가 아니면 답은 항상 존재함
		cout << "YES\n";

		for (int i = 0; i < n; i++) {
			// 총합이 x가 아니라면 i + 1은 항상 n보다 작다
			if (w[i] == x)
				swap(w[i], w[i + 1]);
			cout << w[i] << ' ';
			x -= w[i];
		}
	}

	return 0;
}