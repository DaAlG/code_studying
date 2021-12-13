#include <iostream>

int main() {
	int a;
	scanf("%d", &a);
	if (90 <= a && a <= 100) {
		printf("A\n");
	}else if (70 <= a && a < 90 ) {
		printf("B\n");
	}else if (40 <= a && a < 70) {
		printf("C\n");
	}
	else {
		printf("D\n");
	}
}