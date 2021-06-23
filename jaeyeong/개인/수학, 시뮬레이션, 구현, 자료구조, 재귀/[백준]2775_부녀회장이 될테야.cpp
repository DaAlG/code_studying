using namespace std;
#include <iostream>
#include <cmath>

int apartment[15][15];

int sum(int k, int n) {
	int res = 0;
	for (int i = 1; i <= n; i++)
		res += apartment[k - 1][i];
	return res;
}
int main() {
	int tc;
	cin >> tc;
	for (int i = 1; i <= 14; i++)
		apartment[0][i] = i;
	for (int i = 1; i <= 14; i++) {//��
		for (int j = 1; j <= 14; j++) {//ȣ��
			apartment[i][j] = sum(i, j);
		}
	}

	while (tc--) {
		int k, n;
		cin >> k >> n; //k���� nȣ
		cout << apartment[k][n] << '\n';
	}
}