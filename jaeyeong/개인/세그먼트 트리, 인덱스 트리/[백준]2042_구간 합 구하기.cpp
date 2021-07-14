using namespace std;

#include <iostream>
#define MAX (1<<21)
#define PIV ((1 << 20)-1)
long long tree[PIV * 2];

void update(long long n, long long v) { //n��° ���� ��尪�� v�� �ٲٱ�.
	n += PIV;
	tree[n] = v;
	//���� ���� ���� ������Ʈ ����
	while ((n = n / 2) > 0) { //���� �ٴٸ� ������
		//�� �� ���� = �����ڽ� + �������ڽ�
		tree[n] = tree[n * 2] + tree[n * 2 + 1];
	}
}

long long query(long long l, long long r) { //l ~ r������ ������
	l += PIV, r += PIV;
	long long ret = 0;
	while (l <= r) {
		if (l % 2 == 1) ret += tree[l++]; //l�� ��� ������ Ȧ�� ������ ��带 ���ϱ�
		if (r % 2 == 0) ret += tree[r--]; //r�� ��� ������ ¦�� ������ ��带 ���ϱ�
		l /= 2, r /= 2;
	}
	return ret;
}
int main() {
	int n, m, k;
	long long a, b, c;

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		update((long long)i, a);
	}
	for (int i = 0; i < m + k; i++) {

		cin >> a >> b >> c;
		if (a == 1) update(b, c);
		else cout << query(b, c) << '\n';
	}

}