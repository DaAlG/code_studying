#include <iostream>

int main() {
	int a;
	char odd[] = "odd", even[] = "even", minus[]="minus", plus[]="plus";
	scanf("%d", &a);
	printf("%s\n", a < 0 ? minus : plus);
	printf("%s\n", a % 2 == 0 ? even : odd);
}