/*
���� s�� �־����� ��, ���� s�� �κ� ������ ������ ���� �� ���� ���� ���� �ڿ����� ���ϴ� ����
*/
#include<iostream>
using namespace std;
bool c[200 * 100000 + 10];
int a[20];
int n;
void go(int i, int sum) {
	if (i == n) {
		c[sum] = true;//���� ����� c[i]�� true : i�� ���� �� ���� ��
		return;
	}
	go(i + 1, sum + a[i]);
	go(i + 1, sum);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	go(0, 0);
	for (int i = 0;; i++) //���� ���� �� ���� ���鼭 false�� ������ break;
		if (c[i] == false) {
			cout << i << '\n';
			break;
		}
	return 0;
}