/*
 * 브루트포스
 * 14620 꽃길
 */

#include <iostream>
#define MAX 10
using namespace std;

int n;
int map[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

// 1년 후에 꽃이 제대로 필 수 있는지 확인
bool possible(int x, int y)
{
	if (visited[x][y]) return false;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n) return false;
		if (visited[nx][ny]) return false;
	}
	return true;
}

int go(int cnt, int sum)
{
	// 씨앗 세 개를 다 심었으면 종료
	if (cnt == 3) {
		return sum;
	}

	int ret = 1000000;
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			if (possible(i, j)) {
				// 화단 대여 가격
				int tSum = map[i][j];

				visited[i][j] = true;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					visited[nx][ny] = true;
					tSum += map[nx][ny];
				}

				// 다른 씨앗을 심는다
				ret = min(ret, go(cnt + 1, sum + tSum));

				// 원래대로 돌려준다
				visited[i][j] = false;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					visited[nx][ny] = false;
				}
			}
		}
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	cout << go(0, 0);

	return 0;
}