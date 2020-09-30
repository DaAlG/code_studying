#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool check(vector<int> &perm, vector<char> &a) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '<' && perm[i] > perm[i + 1]) {
			return false;
		}
		if (a[i] == '>' && perm[i] < perm[i + 1]) {
			return false;
		}
	}

	return true;
}

int main() {
	int k;
	cin >> k;
	vector<char> a(k); // 부등호
	for (int i = 0; i < k; i++) {
		cin >> a[i];
	}

	vector<int> small(k + 1); // 가장 작은 수
	vector<int> big(k + 1); // 가장 큰 수
	for (int i = 0; i <= k; i++) {
		small[i] = i;		// 0~k
		big[i] = 9 - i;		// 9~(9-k)
	}

	// 가장 작은 수 찾기 (0123 ~ 3210)
	do {
		if (check(small, a)) {
			break;
		}
	} while (next_permutation(small.begin(), small.end()));

	// 가장 큰 수 찾기 (9876 ~ 6789)
	do {
		if (check(big, a)) {
			break;
		}
	} while (prev_permutation(big.begin(), big.end()));

	for (int i = 0; i < small.size(); i++) {
		cout << big[i];
	}
	cout << '\n';

	for (int i = 0; i < small.size(); i++) {
		cout << small[i];
	}
	cout << '\n';

	return 0;
}