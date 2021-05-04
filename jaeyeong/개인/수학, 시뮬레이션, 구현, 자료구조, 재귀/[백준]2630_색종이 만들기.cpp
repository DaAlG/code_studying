using namespace std;
#include <iostream>
#include <cmath>

int n;
int input[128][128];
int white = 0, blue = 0;

bool check(int k, int sx, int sy) {
	int org = input[sx][sy];
	for (int i = sx; i < sx + k; i++) {
		for (int j = sy; j < sy + k; j++) {
			if (input[i][j] != org)
				return false;
		}
	}
	return true;
}

void solve(int k, int sx, int sy) {
	if (check(k, sx, sy) == false)
		solve(k / 2, sx, sy);
	else {
		if (input[sx][sy] == 1) blue++;
		else white++;
	}
	if (check(k, sx + k, sy) == false)
		solve(k / 2, sx + k, sy);
	else {
		if (input[sx + k][sy] == 1) blue++;
		else white++;
	}
	if (check(k, sx, sy + k) == false)
		solve(k / 2, sx, sy + k);
	else {
		if (input[sx][sy + k] == 1) blue++;
		else white++;
	}
	if (check(k, sx + k, sy + k) == false)
		solve(k / 2, sx + k, sy + k);
	else {
		if (input[sx + k][sy + k] == 1) blue++;
		else white++;
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> input[i][j];
		}
	}
	if (check(n, 0, 0) == true) {
		if (input[0][0] == 1) blue++;
		else white++;
	}else
	solve(n/2, 0, 0);
	cout << white << '\n' << blue << '\n';
}