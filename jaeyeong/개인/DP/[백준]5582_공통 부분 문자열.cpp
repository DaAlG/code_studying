using namespace std;
#include <iostream>

int arr[4005][4005];
string a, b;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b;
	int asize = a.size();
	int bsize = b.size();
	int ans = 0;
	
	for (int i = 1; i <= asize; i++) {
		for (int j = 1; j <= bsize; j++) {
			if (a[i - 1] == b[j - 1]) {
				arr[i][j] = arr[i - 1][j - 1] + 1;
				ans = max(arr[i][j], ans);
			}
			else arr[i][j] = 0;
		}
	}
	cout << ans << '\n';
	return 0;
}