#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n)); // �ɷ�ġ �迭
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	vector<int> b(n); // ����
	for (int i = 0; i < n / 2; i++) {
		b[i] = 1;
	}
	sort(b.begin(), b.end());

	int ans = 2147483647;
	do {
		vector<int> first, second; // 1��, 2��
		for (int i = 0; i < n; i++) {
			if (b[i] == 0) {
				first.push_back(i);
			}
			else {
				second.push_back(i);
			}
		}

		// �ɷ�ġ
		int one = 0;
		int two = 0;
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				one += a[first[i]][first[j]];
				two += a[second[i]][second[j]];
			}
		}
		int diff = one - two;
		if (diff < 0) diff = -diff;
		if (ans > diff) ans = diff;
	} while (next_permutation(b.begin(), b.end()));
	cout << ans << '\n';

	return 0;
}