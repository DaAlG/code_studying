using namespace std;
#include <iostream>
#include <vector>


int d[100001],w[101], v[101];
int n, k;
void backpack(int weight, int value, int index) {
	for (int i = 1; i <= n; i++) {
		for (int j = k; j > 0; j--) {
			if (w[i] <= j)
				d[j] = max(d[j], d[j - w[i]] + v[i]);
		}
	}
	cout << d[k] << '\n';
}
int main() {
	int x, y;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}
	backpack(0, 0, 0);

	return 0;
}