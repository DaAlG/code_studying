/* 그리디
 * 2873 롤러코스터
 * 롤러코스터는 가장 왼쪽 위 칸에서 시작할 것이고, 가장 오른쪽 아래 칸에서 도착할 것이다
 * 각 칸에는 그 칸을 지나갈 때, 탑승자가 얻을 수 있는 기쁨을 나타낸 숫자가 적혀있따
 * 가장 큰 기쁨을 주는 롤러코스터는 어떻게 움직여야 하는지 출력
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void append(string& s, char c, int cnt)
{
	for (int i = 0; i < cnt; i++)
		s += c;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int r, c;
	int map[1000][1000];
	cin >> r >> c;

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> map[i][j];

	string ans;
	if (r % 2) { // r이 홀수
		for (int i = 0; i < r; i++) {
			if (i % 2 == 0) 
				append(ans, 'R', c - 1);
			else 
				append(ans, 'L', c - 1);

			if (i != r - 1) 
				append(ans, 'D', 1);
		}
	}
	else if (c % 2) { // r이 짝수이고 c가 홀수
		for (int i = 0; i < c; i++) {
			if (i % 2 == 0)
				append(ans, 'D', r - 1);
			else
				append(ans, 'U', r - 1);

			if (i != c - 1)
				append(ans, 'R', 1);
		}
	}
	else { // r, c가 모두 짝수
		// 모든 칸이 체스판처럼 검은색과 흰색으로 칠했다고 생각했을 때
		// 흰 칸 한 칸을 방문하지 않기로 하면 도착점까지 남은 칸을 모두 방문할 수 없다
		// 검은색 칸 하나를 방문하지 않기로 한다면 도착점까지 남은 칸을 모두 방문할 수 있다
		// 따라서 검은색 칸 중에 가장 작은 값을 검정 칸을 선택한다
		int x = 0, y = 1;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if ((i + j) % 2 && map[x][y] > map[i][j]) {
					x = i; y = j;
				}
			}
		}

		int x1 = 0;
		int y1 = 0;
		int x2 = r - 1;
		int y2 = c - 1;
		string s;

		while (x2 - x1 > 1) {
			// 선택한 칸이 있는 두 행을 제외하고
			// 첫 행의 제일 오른쪽으로 갔다가 한 칸 내려오고
			// 두번쨰 칸의 제일 왼쪽으로 이동한 다음 한 칸 아래로 내려오는 것 반복
			if (x1 / 2 < x / 2) {
				append(ans, 'R', c - 1);
				append(ans, 'D', 1);
				append(ans, 'L', c - 1);
				append(ans, 'D', 1);
				x1 += 2;
			}
			if (x / 2 < x2 / 2) {
				append(s, 'R', c - 1);
				append(s, 'D', 1);
				append(s, 'L', c - 1);
				append(s, 'D', 1);
				x2 -= 2;
			}
		}

		// 행과 같은 방식으로 열을 처리하면 2*2 크기의 칸만 남는다
		while (y2 - y1 > 1) {
			if (y1 / 2 < y / 2) {
				append(ans, 'D', 1);
				append(ans, 'R', 1);
				append(ans, 'U', 1);
				append(ans, 'R', 1);
				y1 += 2;
			}
			if (y / 2 < y2 / 2) {
				append(s, 'D', 1);
				append(s, 'R', 1);
				append(s, 'U', 1);
				append(s, 'R', 1);
				y2 -= 2;
			}
		}

		if (y == y1) {
			append(ans, 'R', 1);
			append(ans, 'D', 1);
		}
		else {
			append(ans, 'D', 1);
			append(ans, 'R', 1);
		}
		reverse(s.begin(), s.end());
		ans += s;
	}

	cout << ans;
	return 0;
}