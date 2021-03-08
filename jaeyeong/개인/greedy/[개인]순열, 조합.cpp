//nCr = n-1Cr-1 + n-1Cr;
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

void permutation(vector<int> v) {
	sort(v.begin(), v.end());
	do {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
	} while (next_permutation(v.begin(), v.end()));
}
void combination(vector<int> v, vector<int> comb, int index, int r, int depth) {
	if (r == 0) {
		for (int i = 0; i < comb.size(); i++) {
			cout << comb[i] << ' ';
		}
		cout << '\n';
	}
	else if (depth == v.size()) {
		return;
	}
	else {
		comb[index] = v[depth];
		combination(v, comb, index + 1, r - 1, depth + 1);
		combination(v, comb, index, r, depth + 1);
	}
}
int main() {
	vector<int> v = { 3,4,2,1 };
	vector<int> comb(2);
	//순열
	cout << "-----permutation-----\n";
	permutation(v);
	//조합 4C2
	cout << "-----combination-----\n";
	sort(v.begin(), v.end());
	combination(v, comb, 0, 2, 0);
}