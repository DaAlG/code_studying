using namespace std;
#include <iostream>

int n, m;
int arr[301][301];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	int k;
	int a, b, c, d;
	cin >> k;
	while (k--) {
		int sum = 0;
		cin >> a >> b >> c >> d;
		for (int i = a; i <= c; i++) {
			for (int j = b; j <= d; j++) {
				sum += arr[i][j];
			}
		}
		cout << sum << '\n';
	}
}