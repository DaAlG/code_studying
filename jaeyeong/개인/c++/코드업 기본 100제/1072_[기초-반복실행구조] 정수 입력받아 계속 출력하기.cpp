#include <iostream>

int main() {
	int n, m;
	scanf("%d", &n);
reget: //���̺��� �ݷ�( : ) ���� ������.
	scanf("%d", &m);
	printf("%d\n", m);
	if (--n != 0) goto reget;
}