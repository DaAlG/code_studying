using namespace std;
#include <iostream>
#include <vector>
#include <cstring>
#define INF 31

int clocks[16];
int visit[10];

vector<int> switches[10] = {
	{0,1,2},{3,7,9,11},{4,10,14,15},{0, 4, 5, 6, 7},
	{6, 7, 8, 10, 12}, {0, 2, 14, 15}, {3, 14, 15},
	{4, 5, 7, 14, 15}, {1, 2, 3, 4, 5}, {3, 4, 5, 9, 13}
};

bool check() {
	for (int i = 0; i < 16; i++)
		if (clocks[i] != 12) return false;
	return true;
}

void clickSwitch(int idx) {
	for (int i = 0; i < switches[idx].size(); i++) {
		clocks[switches[idx][i]] += 3;
		if (clocks[switches[idx][i]] == 15)
			clocks[switches[idx][i]] = 3;
		else if (clocks[switches[idx][i]] == 0)
			clocks[switches[idx][i]] = 12;
	}
}
int solve(int curSwitch) {
	//모든 스위치를 다 눌러봤을 때
	if (curSwitch == 10) {
		if (check()) return 0;
		else return INF;
	}
	int result = INF;
	for (int i = 0; i < 4; i++) {
		result = min(result, i + solve(curSwitch + 1));
		clickSwitch(curSwitch);
	}
	return result;
}
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		for (int i = 0; i < 16; i++)
			cin >> clocks[i];
		int ans = solve(0);
		if (ans >= INF) ans = -1;
		cout << ans << '\n';
		memset(visit, false, sizeof(visit));
	}
}