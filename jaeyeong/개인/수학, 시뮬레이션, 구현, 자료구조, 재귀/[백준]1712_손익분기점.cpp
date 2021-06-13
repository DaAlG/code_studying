using namespace std;
#include <iostream>

int main() {
	int a; //고정비용
	int b; //가변비용
	int c; //개당 가격
	cin >> a >> b >> c;
	if (b >= c) {
		cout << "-1\n";
		return 0;
	}
	int res = a / (c - b); // res보다 큰 n 필요
	cout << res+1 << '\n';
	return 0;
}