#include <iostream>

int main() {
	int d1, d2, d3, day=1;
	scanf("%d %d %d", &d1, &d2, &d3);
	while(1){
		if (day % d1 == 0 && day % d2 == 0 && day % d3 == 0)
			break;
		day++;
	}
	printf("%d", day);
}