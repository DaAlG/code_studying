using namespace std;
#include <iostream>
#include <algorithm>
#define MAX 500000

int a[MAX], f[MAX];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> f[i];

	for (int k = 0; k < m; k++) {
		int left = 0, right = n - 1;
		bool flag = false;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (a[mid] == f[k]) {
				cout << "1 ";
				flag = true;
				break;
			}
			else if (a[mid] > f[k]) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		if (flag == false) cout << "0 ";
	}
	cout << '\n';
}