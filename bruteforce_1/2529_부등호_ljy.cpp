/*
* <�ε�ȣ>
* �ε�ȣ ��ȣ < �� >�� ������ ���� A�� �ִ�.
* ��ȣ�� ��, �ڿ� �� �ڸ� ���ڸ� �־ ��� �ε�ȣ ���踦 ������Ű���� �Ѵ�.
* �� ��, ���õ� ���� ��� �޶�� �Ѵ�.
* k���� �ε�ȣ ���踦 ��� ������Ű�� (k+1)�� �ڸ��� ���� �߿��� �ִ밪�� �ּҰ��� ���ϴ� ����
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
	vector<int> small(k + 1); //���� ������
	vector<int> big(k + 1); //���� ū ��
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