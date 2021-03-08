#include <iostream>

int main() {
	long long int w,h,b;
	long long int storage;
	double result;

	scanf("%lld %lld %lld", &w, &h,&b);
	storage = w * h * b;

	result = (double)storage / 8388608;

	printf("%.2lf MB", result);
}