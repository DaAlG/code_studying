/*
���� �ٸ� N���� ������ �̷���� ������ ���� ��, ũ�⤿ ����� �κ� ���� �߿��� �� ������ ���Ҹ� �� ���� ���� S�� �Ǵ� ����� ���� ���ϴ� ����
�κ� ������ ����=2^n
ũ�Ⱑ ����� �κм��� = 2^n-1
��� �κ� ������ ���غ��� s�� ���� ��찡 �ִ��� ������ check
o(2^n)
*/
#include<iostream>
using namespace std;
int a[20];
int n, m;
int ans = 0;
/*
go(index, sum)
index : �κ� ������ �������� ���� �����ؾ��ϴ� �ε���
sum: ������� �κм����� ��
1. ������ ã�� ���: index ==n && sum ==m
2. �Ұ����� ���: index == n && sum!=m
3. �������:
	index ��°�� �κм����� �߰�: go(index+1,sum+a[i])
	index ��°�� �κм����� �߰����� ����: go(index+1,sum)))
*/
void go(int i, int sum) {
	if (i == n) {
		if (sum == m)
			ans += 1;
		return;
	}
	go(i + 1, sum + a[i]);
	go(i + 1, sum);
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	go(0, 0);
	if (m == 0) ans -= 1;//�� �־�� �� ũ�Ⱑ ����� �κм����� ����Լ������� �����ϹǷ� ���� 0�� �� (���� �������� ���� ���)
	cout << ans << '\n';
	return 0;
}