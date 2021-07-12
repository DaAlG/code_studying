using namespace std;
#include <iostream>
#include <vector>
#define MAX 101
/*
���� ������ ���������� �������� Ž���ϸ鼭 +1 �� ������ ����
�� ���� ������ ���������̴�.
d ����
0: x��ǥ�� �����ϴ� ���� (��)
1: y��ǥ�� �����ϴ� ���� (��)
2: x��ǥ�� �����ϴ� ���� (��)
3: y��ǥ�� �����ϴ� ���� (��)
*/

int board[MAX][MAX];
int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };
int n;//�巡�� Ŀ�� ��
int x, y, d, g; // (x,y) �巡���ͺ� ���� ��, d ���� ����, g ����
vector<int> dir_info;// 0 = �� , 1 = �� , 2 = �� , 3 = ��

void make_dragon_curve() {
	int size = dir_info.size();
	for (int i = size - 1; i >= 0; i--)
	{
		int nD = (dir_info[i] + 1) % 4;
		x += dx[nD];
		y += dy[nD];
		board[x][y] = 1;
		dir_info.push_back(nD);
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> y >> x >> d >> g;
		dir_info.clear();
		
		board[x][y] = 1;
		x += dx[d];
		y += dy[d];
		board[x][y] = 1;

		dir_info.push_back(d);
		for (int j = 0; j < g; j++)
			make_dragon_curve();
	}
	//�Ⱑ 1��1�� ���簢���� �� ��������
	//��� �巡�� Ŀ���� �Ϻ��� ���� ���� ���ϱ�
	int cnt = 0;
	for (int i = 0; i < MAX-1; i++) {
		for (int j = 0; j < MAX-1; j++) {
			if (board[i][j] == 1 && board[i + 1][j] == 1 &&
				board[i][j + 1] == 1 && board[i + 1][j + 1] == 1)
				cnt++;
		}
	}
	cout << cnt << '\n';
}