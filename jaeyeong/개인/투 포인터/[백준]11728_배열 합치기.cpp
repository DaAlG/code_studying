using namespace std;
#include <iostream>
#include <algorithm>
#define MAX 1000001

int arr[MAX], brr[MAX], ans[MAX];
int n, m;

void merge() {
	int a = 0, b = 0, k = 0;
	while (a < n && b < m) {
		if (arr[a] < brr[b]) ans[k++] = arr[a++];
		else ans[k++] = brr[b++];
	}
	while (a < n) ans[k++] = arr[a++];
	while (b < m) ans[k++] = brr[b++];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < m; i++)
		cin >> brr[i];
	merge();
	int length = n + m;
	for (int i = 0; i <length; i++)
		cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}