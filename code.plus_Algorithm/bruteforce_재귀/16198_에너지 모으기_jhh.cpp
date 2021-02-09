/*
n���� ������ ������ �ְ�, i��° ������ ������ ���Դ� W[1],W[2],...,W[N]�̴�. N<=10
�������� ������ ����� ������ ����
	1.������ ������ �ϳ� ����. ù��°�� �������� �� �� ����. �� ������ ��ȣ�� x��� �Ѵ�.
	2. x��° ������ �����Ѵ�.
	3. W[x-1]*W[x+1]�� �������� ������
	4. N�� 1 ���ҽ�Ű��, ������ ��ȣ�� �ٽ� �ű��.

�������� ������ ��ü ����� ������ ��� ������ = n���϶��� n-2�� �� �� ����
=>(n-2)!=8!
*/
#include<iostream>
#include<vector>
using namespace std;
int go(vector<int>& a) {
	int n = a.size();
	if (n == 2) return 0; //2���� ������ ���� �� ����
	int ans = 0;
	for (int i = 1; i < n - 1; i++) { //�������� energy ã��
		int energy = a[i - 1] * a[i + 1];
		vector<int> b(a);
		b.erase(b.begin() + i);
		energy += go(b);
		if (ans < energy) ans = energy;
	}
	return ans;
}
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i]; 
	cout << go(a) << '\n'; //�迭 ��ü�� �Ѱ���
	return 0;
}