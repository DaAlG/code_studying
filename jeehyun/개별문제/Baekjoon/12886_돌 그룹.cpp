/*
 * 그래프
 * 12886 돌 그룹
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 501
using namespace std;

class Rock {
public :
	int a;
	int b;
	int c;
	Rock(int a, int b, int c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}
};

bool visited[MAX][MAX][MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B, C;
	cin >> A >> B >> C;

	int rmax = max(A, max(B, C));
	int rmin = min(A, min(B, C));
	int rmid = (A + B + C) - (rmax + rmin);

	queue<Rock> q;
	q.push(Rock(rmin, rmid, rmax));
	visited[rmin][rmid][rmax] = true;

	while (!q.empty()) {
		int x = q.front().a;
		int y = q.front().b;
		int z = q.front().c;
		q.pop();

		if (x == y && y == z) {
			cout << 1;
			return 0;
		}

		// a < b
		int tmpx = x + x;
		int tmpy = y - x;
		int tmpz = z;

		if (tmpy > 0) {
			int tmpmax = max(tmpx, max(tmpy, tmpz));
			int tmpmin = min(tmpx, min(tmpy, tmpz));
			int tmpmid = (tmpx + tmpy + tmpz) - (tmpmax + tmpmin);

			if (!visited[tmpmin][tmpmid][tmpmax]) {
				visited[tmpmin][tmpmid][tmpmax] = true;
				q.push(Rock(tmpmin, tmpmid, tmpmax));
			}
		}

		// a < c
		tmpx = x + x;
		tmpy = y;
		tmpz = z - x;

		if (tmpz > 0) {
			int tmpmax = max(tmpx, max(tmpy, tmpz));
			int tmpmin = min(tmpx, min(tmpy, tmpz));
			int tmpmid = (tmpx + tmpy + tmpz) - (tmpmax + tmpmin);

			if (!visited[tmpmin][tmpmid][tmpmax]) {
				visited[tmpmin][tmpmid][tmpmax] = true;
				q.push(Rock(tmpmin, tmpmid, tmpmax));
			}
		}

		// b < c
		tmpx = x;
		tmpy = y + y;
		tmpz = z - y;

		if (tmpz > 0) {
			int tmpmax = max(tmpx, max(tmpy, tmpz));
			int tmpmin = min(tmpx, min(tmpy, tmpz));
			int tmpmid = (tmpx + tmpy + tmpz) - (tmpmax + tmpmin);

			if (!visited[tmpmin][tmpmid][tmpmax]) {
				visited[tmpmin][tmpmid][tmpmax] = true;
				q.push(Rock(tmpmin, tmpmid, tmpmax));
			}
		}
	}

	cout << 0;
	return 0;
}