/*
* <부등호>
* 부등호 기호 < 와 >가 나열된 수열 A가 있다.
* 기호의 앞, 뒤에 한 자리 숫자를 넣어서 모든 부등호 관계를 만족시키려고 한다.
* 이 때, 선택된 수는 모두 달라야 한다.
* k개의 부등호 관계를 모두 만족시키는 (k+1)개 자리의 정수 중에서 최대값과 최소값을 구하는 문제
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool check(vecor<int>& perm, vector<char>& a) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '<' && perm[i] > perm[i + 1])
			return false;
		if (a[i] == '>' && perm[i] < perm[i + 1])
			return false;
	}
	return true;
}
int main() {
	int k;
	cin >> k;
	vector<char> a(k);

	for (int i = 0; i < k; i++) {
		cin >> a[i];
	}
	vector<int> small(k + 1); //가장 작은수
	vector<int> big(k + 1); //가장 큰 수
	for (int i = 0; i <= k; i++) {
		small[i] = i;
		big[i] = 9 - i;
	}

	do {
		if (check(small, a)) {
			break;
		}
	} while (next_permutation(small.begin(), small.end()));
	do {
		if (check(big, a)) {
			break;
		}
	} while (next_permutation(big.begin(), big.end()));

	for (int i = 0; i < small.size(); i++) {
		cout << small[i];
	}
	cout << '\n';

	for (int i = 0; i < small.size(); i++) {
		cout << small[i];
	}
	cout << '\n';

	return 0;


}