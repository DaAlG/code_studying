/*
!!!!!!!!���-��Ʈ��ŷ!!!!!!!
<N-Queen>
N*Nũ���� ü���� ���� �� N���� ���� ������ �� ���� ���� ����
N�� �־����� ��, ���� ���� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�

(�Է�)
ù° �ٿ� N�� �־����� (1 �� N < 15)

(���)
ù° �ٿ� �� N���� ���� ������ �� ���� ���� ����� ���� ���
*/

#include <iostream>

using namespace std;

bool a[15][15];
int n;
bool check_col[15];
bool check_dig[40];
bool check_dig2[40];

//��, �Ʒ�, �밢�����⿡ ���� ������ return true
bool check(int row, int col) {
	//�ش� ��(column)�� �ִ°�
	if (check_col[col]) {
		return false;
	}
	// (/)���� �밢���� ���� ������ true
	if (check_dig[row+col]) {
		return false;
	}
	// �ٹ��� �밢���� ���� ������ true
	if (check_dig2[row-col+n]) {
		return false;
	}
	return true;
}

//calc(row): row �࿡ ���� ��� ������ �����ϴ� function
int calc(int row) {
	if (row == n) {
		//ans += 1;
		return 1;
	}
	int cnt = 0;
	for (int col = 0; col < n; col++) {
		if (check(row, col)) {
			//check����Ʈ, board ó��
			check_dig[row + col] = true;
			check_dig2[row - col + n] = true;
			check_col[col] = true;
			a[row][col] = true;
			//���� ��(row)�� ���� ����
			cnt += calc(row + 1);
			//����
			check_dig[row + col] = false;
			check_dig2[row - col + n] = false;
			check_col[col] = false;
			a[row][col] = false;
		}
	}
	return cnt;
}
int main() {
	cin >> n;
	cout << calc(0) << '\n';
	return 0;
}