using namespace std;
#include <iostream>
#include <cmath>

int main() {
	long long a, b, v;
	cin >> a >> b >> v;
	double c = (double)(v - a) / (double)(a - b);
	//(a-b)(day-1)+a >= v
	long long day = ceil(c) + 1;
	cout << day << '\n';
}