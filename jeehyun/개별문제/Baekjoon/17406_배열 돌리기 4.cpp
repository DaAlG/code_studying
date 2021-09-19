#include <iostream>
#include <vector>
#include <cstring>
#define INF 987654321
using namespace std;

struct Info {
	int sx, sy, ex, ey;
	Info(int r, int c, int s) : sx(r - s), sy(c - s), ex(r + s), ey(c + s) { }
};

int n, m, k;
int a[51][51];
int na[51][51];
bool visited[6];
vector<Info> info;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

bool isWall(int x, int y, Info info)
{
	return x < info.sx || x > info.ex || y < info.sy || y > info.ey;
}

void rotate(Info info)
{
	int b[51][51]; // 연산을 수행한 결과를 저장할 배열
	memset(b, 0, sizeof(b));

	int dir = 0;
	int x, y; // 현재 위치

	// 다음 위치
	int nx = info.sx; 
	int ny = info.sy;

	int r = info.ex - info.sx + 1;
	int c = info.ey - info.sy + 1;

	while (1) {
		int cnt = (r + c - 2) * 2; // 이동시킬 칸 개수
		
		if (cnt < 1) { // 더 이상 이동시킬 게 없으면 마지막 원소를 b 배열에 저장하고 종료
			b[nx][ny] = na[nx][ny];
			break;
		}

		for (int i = 0; i < cnt; i++) {
			x = nx;
			y = ny;

			nx = x + dx[dir];
			ny = y + dy[dir];

			// 벽이거나 이미 들렀던 곳이면 방향을 바꾼다
			if (isWall(nx, ny, info) || b[nx][ny] != 0) { 
				dir = (dir + 1) % 4;
				nx = x + dx[dir];
				ny = y + dy[dir];
			}

			// 현재 칸의 수를 다음 칸에 저장
			b[nx][ny] = na[x][y];
		}
		r -= 2; c -= 2;
		nx += 1; ny += 1;
	}

	// 회전 결과를 na 배열에 저장한다
	for (int i = info.sx; i <= info.ex; i++) {
		for (int j = info.sy; j <= info.ey; j++) {
			na[i][j] = b[i][j];
		}
	}
}

// 배열의 값 구하기 (각 행에 있는 모든 수의 합 중 최솟값)
int calc()
{
	int result = INF;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= m; j++) {
			sum += na[i][j];
		}
		result = min(result, sum);
	}
	return result;
}

int go(vector<int> seq) 
{
	if (seq.size() == info.size()) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				na[i][j] = a[i][j];
			}
		}

		// 회전 연산 수행
		for (int i = 0; i < seq.size(); i++) {
			rotate(info[seq[i]]);
		}

		return calc();
	}

	int ret = INF;
	for (int next = 0; next < info.size(); next++) {
		if (!visited[next]) {
			// 다음 연산 선택
			seq.push_back(next); 
			visited[next] = true;

			ret = min(ret, go(seq));

			// 원래대로
			seq.pop_back(); 
			visited[next] = false;
		}
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		info.push_back(Info(r, c, s));
	}

	cout << go(vector<int>());
	return 0;
}