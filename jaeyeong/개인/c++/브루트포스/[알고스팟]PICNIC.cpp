using namespace std;
#include <iostream>
#include <cstring>

int n, m;
bool areFriends[10][10];
//taken[i] = i��° �л��� ¦�� �̹� ã�Ҵٸ� true, �ƴϸ� false
bool taken[10];

int solve() {
	//���� �л��� �� ���� ��ȣ�� ���� �л��� ã�´�.
	int firstFree = -1;
	for (int i = 0; i < n; i++) {
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}
	//���� ���: ��� �л��� ¦�� ã������ �� ���� ����� ã������ �����Ѵ�.
	if (firstFree == -1) return 1;
	int ret = 0;
	//�� �л��� ¦���� �л��� �����Ѵ�.
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