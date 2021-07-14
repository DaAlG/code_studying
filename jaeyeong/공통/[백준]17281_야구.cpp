using namespace std;
#include <iostream>
#include <vector>
#include <cstring>

int player[50][9];
vector<int> selected;
bool isSelected[9];
int answer = -1, n;

int asRule[4][5] = {
	{0, 1, 2, 3, 4},
	{0,1,2,3,3},
	{0,1,2,2,2},
	{0,1,1,1,1}
}; //[i][j] == j번 결과가 나왔을 때 i번 위치의 선수가 움직이는 수

int score() {
	bool onField[4] = { false, }; //k루야에 선수가 있는지
	int res = 0;
	int idx = 0;

	for (int i = 0; i < n; i++) {
		int out_cnt = 0;
		memset(onField, false, sizeof(onField));
		while (out_cnt < 3) {
			int thisPlayer = selected[idx];
			int thisRes = player[i][thisPlayer]; //이번 선수가 낸 결과

			if (thisRes == 0) {
				out_cnt++;
			}
			else {
				onField[0] = true;

				for (int k = 3; 0 <= k; k--) {
					if (onField[k] == true) {
						onField[k] = false;
						int next = k + asRule[k][thisRes];
						if (next >= 4) {
							res++;
						}
						else onField[next] = true;
					}
				}
			}
			idx++;
			if (idx == 9) idx = 0;
		}
	}
	return res;
}
void select(int cnt) {
	if (cnt == 8) {
		selected.insert(selected.begin() + 3, 0);
		answer = max(score(), answer);
		selected.erase(selected.begin() + 3);
		return;
	}
	for (int i = 1; i < 9; i++) {
		if (!isSelected[i]) {
			isSelected[i] = true;
			selected.push_back(i);
			select(cnt + 1);
			selected.pop_back();
			isSelected[i] = false;
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 9; j++)
			cin >> player[i][j];
	}
	select(0);
	cout << answer << '\n';
}