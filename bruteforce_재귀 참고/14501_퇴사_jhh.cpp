/*
n+1�� �Ǵ� �� ��縦 �Ϸ��� �Ѵ�.
���� n�� ���� �ִ��� ���� ����� �Ϸ��� �Ѵ�.
�Ϸ翡 �ϳ��� ����� �� �� �ְ� i�Ͽ� ����� �ϸ�, t[i]���� �ɸ��� p[i]���� ����
*/
#include<iostream>
using namespace std;
const int inf = -10000000;
int t[21];
int p[21];
int n;
int ans = 0;
void go(int day, int sum) {
	//������ �����鼭 ���� �� ȣ��
	if (day == n + 1) {
		if (ans < sum)ans = sum;
		return;
	}
	if (day > n + 1)
		return;
	go(day + 1, sum);
	go(day + t[day], sum + p[day]);
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> t[i] >> p[i];
	go(1, 0);
	cout << ans << '\n';
	return 0;
}
/*���� �ڵ带 return ���� �̿��ϰ� �����ϸ� ������ ���� ������ �� �ִ� day�Ϸ� ���� ���� �� �ִ�
*/
/*�ǹ��ִ� ��� : �ִ� ������ ������ ���
�պκп��� ���� �ִ��� ģ���� �ִ밡 ��
1~3�� ���� ������ ����� �����ϰ� 4���� �� �Ŀ� 4~6�� ���� ���� �� �ִ� �ִ� ���Ͱ� ����.
������ ��ġ�� �ʴ´ٸ� ���� �� �ִ� ��� 7*/