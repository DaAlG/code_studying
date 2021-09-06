#include <iostream>
#include <cstring>
using namespace std;

int n, m, c;
int honey[10][10];
int profit[10][10];

int harvest(int x, int y, int ynow, int sum, int p)
{
	if (sum > c) return 0;
	if (ynow >= y + m) return p;


	int ret = 0;

	// 선택 X
	ret = max(ret, harvest(x, y, ynow + 1, sum, p));

	// 선택 
	int tmp = honey[x][ynow];
	ret = max(ret, harvest(x, y, ynow + 1, sum + tmp, p + tmp * tmp));
	
	return ret;
}

int find(int x, int y)
{
	int result = 0;
	for (int i = x; i < n; i++) {
		for (int j = 0; j <= n - m; j++) {
			if (i == x && j < y + m) continue;
			result = max(result, profit[x][y] + profit[i][j]);
		}
	}
	return result;
}

int main()
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> n >> m >> c;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> honey[i][j];
			}
		}

		memset(profit, 0, sizeof(profit));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= n - m; j++) {
				profit[i][j] = harvest(i, j, j, 0, 0);
			}
		}

		int answer = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= n - m; j++) {
				answer = max(answer, find(i, j));
			}
		}
		cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;
}