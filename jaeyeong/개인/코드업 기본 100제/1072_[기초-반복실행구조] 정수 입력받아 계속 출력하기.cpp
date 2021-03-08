#include <iostream>

int main() {
	int n, m;
	scanf("%d", &n);
reget: //레이블은 콜론( : ) 으로 끝난다.
	scanf("%d", &m);
	printf("%d\n", m);
	if (--n != 0) goto reget;
}