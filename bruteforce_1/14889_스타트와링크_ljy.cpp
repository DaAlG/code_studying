/*
<��ŸƮ�� ��ũ>
N���� N/2�� �� ������ �������� �Ѵ�. (4��N��20,N�� ¦��)
�� ���� �ɷ�ġ�� ���� ����, ������ �ּҰ��� ���ϴ� ����
S[i][j]=i�� ����� j�� ����� ���� ���� ������ ��, ���� �������� �ɷ�ġ
���� �ɷ�ġ: ���� ���� ��� ���� S[i][j]�� ��
(���)
ù° �ٿ� ��ŸƮ ���� ��ũ ���� �ɷ�ġ�� ���̸� �ּڰ��� ����Ѵ�.
(���� �Է� 1)
4
0 1 2 3
4 0 5 6
7 1 0 2
3 4 5 0
(���� �Է� 2)
6
0 1 2 3 4 5
1 0 2 3 4 5
1 2 0 3 4 5
1 2 3 0 4 5
1 2 3 4 0 5
1 2 3 4 5 0
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	vector<int> b(n);

	for (int i = 0; i < n / 2; i++) {
		b[i] = 1;
	}
	sort(b.begin(), b.end());
	int ans = 2147483647;
	do {
		vector<int> first, second;
		for (int i = 0; i < n; i++) {
			if (b[i] == 0) {
				first.push_back(i);
			}
			else {
				second.push_back(i);
			}
		}
		int one = 0;
		int two = 0;
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				if (i == j) continue;
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