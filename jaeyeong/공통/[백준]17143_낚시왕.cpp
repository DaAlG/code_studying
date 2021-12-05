using namespace std;
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <set>

struct shark {
	int x, y; //��ġ
	int s, d, z; //�ӷ�, �̵�����, ũ��
};

int r, c, m;
int board[101][101];
int direction[5][2] = { {0, 0} ,{-1, 0},{1, 0},{0, 1},{0, -1} };
int fisherman = 0;
shark sharks[10000];
set<int> deadList;

void moveShark() {
	for (int i = 0; i < m; i++) {
		bool flag = false;
		if (deadList.find(i) != deadList.end()) continue;
		if (board[sharks[i].x][sharks[i].y] >= i)
			flag = true;
		if(flag) board[sharks[i].x][sharks[i].y] = -1;
		int roundTrip;
		if (sharks[i].d <= 2) roundTrip = (r-1)*2;
		else roundTrip = (c-1)*2;
		int myS = sharks[i].s % roundTrip;
		while (myS) {
			switch (sharks[i].d) {
			case 1:
				if (sharks[i].x - myS < 1) {
					myS -= (sharks[i].x-1);
					sharks[i].x = 1;
					sharks[i].d = 2;
				}
				else {
					sharks[i].x -= myS;
					myS = 0;
					if (sharks[i].x == 1) sharks[i].d = 2;
				}
				break;
			case 2:
				if (sharks[i].x + myS > r) {
					myS -= (r-sharks[i].x);
					sharks[i].x = r;
					sharks[i].d = 1;
				}
				else {
					sharks[i].x += myS;
					myS = 0;
					if (sharks[i].x == r) sharks[i].d = 1;
				}
				break;
			case 3:
				if (sharks[i].y + myS > c) {
					myS -= (c - sharks[i].y);
					sharks[i].y = c;
					sharks[i].d = 4;
				}
				else {
					sharks[i].y += myS;
					myS = 0;
					if (sharks[i].y == c) sharks[i].d = 4;
				}
				break;
			case 4:
				if (sharks[i].y - myS < 1) {
					myS -= (sharks[i].y-1);
					sharks[i].y = 1;
					sharks[i].d = 3;
				}
				else {
					sharks[i].y -= myS;
					myS = 0;
					if(sharks[i].y==1) sharks[i].d = 3;
				}
				break;
			}
		}
		if (board[sharks[i].x][sharks[i].y]!=-1 && board[sharks[i].x][sharks[i].y] < i)
			deadList.insert(i);
		else board[sharks[i].x][sharks[i].y] = i;
	}
}
int solution() {
	int answer = 0;
	//1. ���ÿ��� ���������� �� ĭ �̵���x��.
	while (fisherman++ < c) {
		//2. ���ÿ��� �ִ� ���� �ִ� ��� �� ���� ���� ����� �� ��´�.
		for (int i = 1; i <= r; i++) {
			if (board[i][fisherman]!=-1) {
				int c = board[i][fisherman];
				answer += sharks[c].z;
				board[i][fisherman] = -1;
				deadList.insert(c);
				break;
			}
		}
		//3. �� �̵��Ѵ�.
		moveShark();
	}
	return answer;
}

bool compare(shark a, shark b) {
	return a.z > b.z;
}
int main() {
	cin >> r >> c >> m;
	memset(board, -1, sizeof(board));
	for (int i = 0; i < m; i++)
		cin >> sharks[i].x >> sharks[i].y >> sharks[i].s >> sharks[i].d >> sharks[i].z;
	sort(sharks, sharks + m, compare);
	for (int i = 0; i < m; i++)
		board[sharks[i].x][sharks[i].y] = i;
	cout << solution() << '\n';
	return 0;
}