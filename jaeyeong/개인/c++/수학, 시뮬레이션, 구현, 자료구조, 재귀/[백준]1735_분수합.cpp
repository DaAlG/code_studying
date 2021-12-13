using namespace std;
#include <iostream>
/*유클리드 호제법
* : 두 정수의 최대 공약수를 구하는 방법
* - 먼저 최대 공약수가 아닌 분모의 곱을 사용하여 합을 구한다
* - 그 후 분모와 분자의 최대공약수를 유클리드 호제법을 사용하여 구하고
* - 
*/
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main() {
	int a, b, c, d, p, q, g;
	cin >> a >> b >> c >> d;
	p = a * d + b * c;//합의 분자
	q = b * d; //합의 분모
	g = gcd(p, q);//최대공약수
	cout << p / g << ' '<<q / g << '\n';
}