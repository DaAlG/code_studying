#include<iostream>
#include <cstring>
using namespace std;

int n;
string dir;
int map[20][20];
bool merged[20][20];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool possible(int nx, int ny, int x, int y)
{
	return (map[nx][ny] == 0 || (!merged[nx][ny] && !merged[x][y] && map[nx][ny] == map[x][y]));
}

void moveUp()
{
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int idx = i;
			while (idx - 1 >= 0 && possible(idx - 1, j, idx, j)) {
				if (map[idx - 1][j] == 0) {
					swap(map[idx - 1][j], map[idx][j]);
				}
				else {
					merged[idx - 1][j] = true;
					map[idx - 1][j] *= 2;
					map[idx][j] = 0;
				}
				idx--;
			}
		}
	}
}

void moveDown()
{
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			int idx = i;
			while (idx + 1 < n && possible(idx + 1, j, idx, j)) {
				if (map[idx + 1][j] == 0) {
					swap(map[idx + 1][j], map[idx][j]);
				}
				else {
					merged[idx + 1][j] = true;
					map[idx + 1][j] *= 2;
					map[idx][j] = 0;
				}
				idx++;
			}
		}
	}
}

void moveLeft()
{
	for (int j = 1; j < n; j++) {
		for (int i = 0; i < n; i++) {
			int idx = j;
			while (idx - 1 >= 0 && possible(i, idx - 1, i, idx)) {
				if (map[i][idx - 1] == 0) {
					swap(map[i][idx - 1], map[i][idx]);
				}
				else {
					merged[i][idx - 1] = true;
					map[i][idx - 1] *= 2;
					map[i][idx] = 0;
				}
				idx--;
			}
		}
	}
}

void moveRight()
{
	for (int j = n - 2; j >= 0; j--) {
		for (int i = 0; i < n; i++) {
			int idx = j;
			while (idx + 1 < n && possible(i, idx + 1, i, idx)) {
				if (map[i][idx + 1] == 0) {
					swap(map[i][idx + 1], map[i][idx]);
				}
				else {
					merged[i][idx + 1] = true;
					map[i][idx + 1] *= 2;
					map[i][idx] = 0;
				}
				idx++;
			}
		}
	}
}

int main(int argc, char** argv)
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case) {
		cin >> n >> dir;

		memset(merged, false, sizeof(merged));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		if (dir == "up") moveUp();
		else if (dir == "down") moveDown();
		else if (dir == "left") moveLeft();
		else if (dir == "right") moveRight();

		cout << "#" << test_case << "\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}