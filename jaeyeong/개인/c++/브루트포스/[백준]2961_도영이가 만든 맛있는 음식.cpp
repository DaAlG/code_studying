using namespace std;
#include <iostream>

int n, ans=0x3f3f3f3f;
int input[11][2], arr[11], visit[11];

int ABS(int m, int s) {
	if (m < s)
		return s - m;
	else
		return m - s;
}

//nCr
void comb(int r, int cnt) {
	if (r == cnt) {
		int mul=1, sum=0, dif;
		for (int i = 1; i <= r; i++) {
			mul *= input[arr[i]][0];
			sum += input[arr[i]][1];
		}
		dif = ABS(mul, sum);
		if (dif < ans) ans = dif;
		return;
	}
	for (int i = arr[cnt]+1; i <= n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			arr[cnt+1] = i;
			comb(r, cnt + 1);
			visit[i] = false;
		}
	}

}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> input[i][0] >> input[i][1];
	for(int i=1;i<=n;i++)
		comb(i, 0);
	cout << ans << '\n';
}