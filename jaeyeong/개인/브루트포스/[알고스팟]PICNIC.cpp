using namespace std;
#include <iostream>
#include <cstring>

int n, m;
bool areFriends[10][10];
//taken[i] = i번째 학생이 짝을 이미 찾았다면 true, 아니면 false
bool taken[10];

int solve() {
	//남은 학생들 중 가장 번호가 빠른 학생을 찾는다.
	int firstFree = -1;
	for (int i = 0; i < n; i++) {
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}
	//기저 사례: 모든 학생이 짝을 찾았으면 한 가지 방법을 찾았으니 종료한다.
	if (firstFree == -1) return 1;
	int ret = 0;
	//이 학생과 짝지을 학생을 결정한다.
	for (int pairWith = firstFree + 1; pairWith < n; pairWith++) {
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			ret += solve();
			taken[firstFree] = taken[pairWith] = false;
		}
	}
	return ret;
}
int main() {
	int tc;
	int x, y;
	cin >> tc;
	while (tc--) {	
		cin >> n >> m;	
		for (int i = 0; i < m; i++) {
			cin >> x >> y;
			areFriends[x][y]=true;
			areFriends[y][x] = true;
		}
		int answer = solve();
		cout << answer << '\n';
		memset(taken, false, sizeof(taken));
		for (int i = 0; i < n; i++)
			memset(areFriends[i], false, sizeof(areFriends[i]));
	}
}