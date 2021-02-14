/* 분할정복
 * 1780 종이의 개수
 */

#include <iostream>
#include <map>
#define MAX 3000
using namespace std;

int n;
int paper[MAX][MAX];
map<int, int> ans;

void cut(int x, int y, int size)
{
	int value = paper[x][y];
	bool check = true;

	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (paper[i][j] != value) {
				check = false;
				break;
			}
		}
	}

	if (!check) {
		for (int i = x; i < x + size; i += size / 3) {
			for (int j = y; j < y + size; j += size / 3) {
				cut(i, j, size / 3);
			}
		}
	}
	else
		ans[value]++;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}

	cut(0, 0, n);

	for (int i = -1; i < 2; i++)
		cout << ans[i] << "\n";

	return 0;
}