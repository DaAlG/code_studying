#include <iostream>
#define MAX 51
using namespace std;

int n, m;
char map[MAX][MAX];
char color[] = { 'B', 'W' };

int repaint(int x, int y, int c)
{
	int cnt = 0;

	for (int i = 0; i < 8; i++) {
		int now = c;
		for (int j = 0; j < 8; j++) {
			if (map[x + i][y + j] != color[(j + c) % 2]) cnt++;
		}
		c = (c + 1) % 2;
	}
	
	return cnt;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	int answer = 2500;
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			answer = min(answer, min(repaint(i, j, 0), repaint(i, j, 1)));
		}
	}
	cout << answer;
	return 0;
}