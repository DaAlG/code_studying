using namespace std;
#include <iostream>
#define INF 0x3f3f3f3f
#define MAX 505

struct st { int l, r; };
st m[MAX];
long long d[MAX][MAX];//d[i][j] = i번째 행렬에서 j번째 행렬까지 곱했을 때 나오는 최소 곱셈 횟수

long long dp(int l, int r) {
	if (d[l][r]) return d[l][r];
	long long ret = INF;
	if (r - l == 1)
		return m[l].l * m[l].r * m[r].r;

	if (r == l) return 0;
	for (int i = l; i <= r - 1; i++) {
		long long lc = dp(l, i);
		long long rc = dp(i + 1, r);
		ret = min(ret, lc + rc + m[l].l * m[i].r * m[r].r);
	}
	d[l][r] = ret;
	return d[l][r];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> m[i].l >> m[i].r;
	cout << dp(1, n) << '\n';
}
