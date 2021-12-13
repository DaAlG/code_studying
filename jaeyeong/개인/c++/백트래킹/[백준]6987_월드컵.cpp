using namespace std;
#include <iostream>
#define team 6

int input[team][3], result[team][3];
int team1[] = { 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4 };
int team2[] = { 1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5, 4, 5, 5 };
int answer[4];
int tc = 0;

void solve(int cnt) {
	if (cnt == 15) {
		for (int i = 0; i < team; i++) {
			for (int j = 0; j < 3; j++) {
				if (input[i][j] != result[i][j])
					return;
			}
		}
		answer[tc] = 1;
		return;
	}
	int t1 = team1[cnt];
	int t2 = team2[cnt];

	//t1½Â, t2ÆĞ
	result[t1][0]++; result[t2][2]++;
	solve(cnt + 1);
	result[t1][0]--; result[t2][2]--;

	//t1ÆĞ, t2½Â
	result[t1][2]++; result[t2][0]++;
	solve(cnt + 1);
	result[t1][2]--; result[t2][0]--;

	//t1¹«, t2¹«
	result[t1][1]++; result[t2][1]++;
	solve(cnt + 1);
	result[t1][1]--; result[t2][1]--;
}
int main() {
	int tnum = 4;
	while (tnum--) {
		for (int i = 0; i < team; i++)
			for (int j = 0; j < 3; j++)
				cin >> input[i][j];

		solve(0);
		tc++;
	}
	for (int i = 0; i < 4; i++)
		cout << answer[i] << ' ';
}