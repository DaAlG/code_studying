/*
k�� ���� �� 6�� ���� ����
k<12 ���� ������ ���
��ü ����� ���� 2^12=4096
���� ����/���� �ʴ´�
*/
#include<iostream>
#include<vector>

using namespace std;
vector<int> lotto; // �Լ��� �� �� ����
void solve(vector<int>& a, int index, int cnt) {// a: �Է����� �־��� ��, index: �������� ���� �����ؾ� �ϴ� index, cnt: ������� ������ ���� ����
	/*
	1. ������ ã�� ���: cnt==6
	2. �Ұ����� ���: ������ ������ �����ϴ� ���� & �Լ� ȣ���� �ص� ���� x , ���̻� �����Ҽ� ���� ���, index==a.size()
	3. ���� ��� ȣ��
		index ��° �� ����: go(a,index+1, cnt+1)
		�������� �ʴ� ���: go(a,index+1,cnt)
	*/
	if (cnt == 6) {//cnt==6 �̸� ���
		for (int num : lotto)
			printf("%d ", num);
		printf("\n");
		return;
	}
	int n = a.size();
	if (n == index) return;
	lotto.push_back(a[index]);//����
	solve(a, index + 1, cnt + 1);
	lotto.pop_back();//���� x
	solve(a, index + 1, cnt);
}

int main() {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		solve(a, 0, 0);
		cout << '\n';
	}
	return 0;
}
/*
6�� ���� ���� ���� ������
�����ϴ� ���� ����
�ݵ�� ���� ���� ������ �� ������? ������ ���ǰ� �Լ� ������ �����ִµ�
���� ���ǿ� k �Է��� ������������ �Է�
i��°�� �����ϴ� ��찡 ���� �ֱ� ������ = ���� ���� �����ϴ°� ����
�׷��� ������ ó�� ���ص� ���������� ��� ������
*/