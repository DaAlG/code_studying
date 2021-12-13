#include <iostream>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		if (i % 3 == 0) printf("X ");
		else printf("%d ", i);
	}
}