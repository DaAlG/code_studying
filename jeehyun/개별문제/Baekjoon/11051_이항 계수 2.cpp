/*
 * 수학
 * 11051 이항 계수 2
 */

#include <iostream>
#define MAX 1001
#define MODULER 10007
using namespace std;

int nCr[MAX][MAX];

void comb(int n) 
{
	nCr[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		nCr[i][0] = 1;
		nCr[i][i] = 1;
		for (int j = 1; j < i; j++) {
			nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % MODULER;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	comb(n);
	cout << nCr[n][k];

	return 0;
}