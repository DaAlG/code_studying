#include <iostream>

int main() {
	long long int s, h, b, c;
	long long int storage;
	double result;

	scanf("%d %d %d %d", &h, &b, &c, &s);
	storage = h * b * c * s;
	
	result = (double)storage / 8388608;

	printf("%.1lf MB", result);
}