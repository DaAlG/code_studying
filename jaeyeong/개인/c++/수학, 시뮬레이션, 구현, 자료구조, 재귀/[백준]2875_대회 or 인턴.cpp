using namespace std;
#include <iostream>

int n, m, k;

int makeTeam(int nn, int mm) {
	int cnt = 0;
	while (nn >= 2 && mm >= 1) {
		nn -= 2;
		mm -= 1;
		cnt ++ ;
	}
	return cnt;
}
int main() {
	int ans=0, res;
	cin >> n >> m >> k;
	for (int i = 0; i <= k; i++) {
		res = makeTeam(n-i, m-(k - i));
		ans = max(res, ans);
	}
	cout << ans << '\n';
}