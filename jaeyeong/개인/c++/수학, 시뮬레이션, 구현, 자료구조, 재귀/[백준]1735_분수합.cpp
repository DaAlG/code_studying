using namespace std;
#include <iostream>
/*��Ŭ���� ȣ����
* : �� ������ �ִ� ������� ���ϴ� ���
* - ���� �ִ� ������� �ƴ� �и��� ���� ����Ͽ� ���� ���Ѵ�
* - �� �� �и�� ������ �ִ������� ��Ŭ���� ȣ������ ����Ͽ� ���ϰ�
* - 
*/
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main() {
	int a, b, c, d, p, q, g;
	cin >> a >> b >> c >> d;
	p = a * d + b * c;//���� ����
	q = b * d; //���� �и�
	g = gcd(p, q);//�ִ�����
	cout << p / g << ' '<<q / g << '\n';
}