#include <iostream>
using namespace std;

int n, m;
int map[20][20];

bool isWall(int x, int y)
{
	return x < 0 || x >= n || y < 0 || y >= n;
}

int secure(int x, int y, int k) 
{
	int cost = k * k + (k - 1) * (k - 1);
	int cnt = 0;

	// 서비스 제공 가능한 집을 찾는다
	int d[] = { -1, 1 };
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < 2; j++) {
			int nx = x + i * d[j];
			int ny = y;

			if (isWall(nx, ny)) continue;

			int num = k - i - 1;
			for (int l = ny - num; l <= ny + num; l++) {
				if (!isWall(nx, l) && map[nx][l])
					cnt++;
			}

			if (i == 0) break;
		}
	}

	if (cnt * m < cost)
		return 0;
	return cnt;
}

int main()
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		int answer = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 1; k <= n + 1; k++) {
					answer = max(answer, secure(i, j, k));
				}
			}
		}
		cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;
}