using namespace std;
#include <iostream>
#include <cstring>
#define MAX 100

int n, l;
int input[MAX][MAX];
bool obstacle[MAX];
int answer = 0;

void solve() {
	for (int i = 0; i < n; i++) {
		memset(obstacle, 0, n);
		for (int j = 0; j < (n-1); j++) {
			if (input[i][j] == input[i][j+1]) {
				if (j == n - 2)
					answer++;
				continue;
			}
			//올라가는 경우
			if (input[i][j]+1 == input[i][j+1]) {
				int cnt = 0;
				int k = j;
				while (input[i][j] == input[i][k] && cnt < l && obstacle[k]==0) {
					k--; cnt++;
					if (k < 0) break;
				}
				if (l == cnt) {
					if (j == n - 2) answer++;

					for (int t = k+1; t <=j; t++)
						obstacle[t] = 1;
					continue;
				}
				else break;
			}
			//내려가는 경우
			else if (input[i][j]-1 == input[i][j + 1]) {
				int cnt = 0;
				int k = j+1;
				while (input[i][j+1] == input[i][k] && cnt < l && obstacle[k] == 0) {
					k++; cnt++;
					if (n <= k) break;
				}
				if (l == cnt) {
					if (k == n) answer++;

					for (int t = j + 1; t < k; t++)
						obstacle[t] = 1;
					j = k - 2;
					continue;
				}
				else break;
			}
			else break;
		}
	}


	for (int i = 0; i < n; i++) {
		memset(obstacle, 0, n);
		for (int j = 0; j < (n-1); j++) {
			if (input[j][i] == input[j + 1][i]) {
				if (j == n - 2)
					answer++;
				continue;
			}
			//올라가는 경우
			if (input[j][i]+1 == input[j+1][i]) {
				int cnt = 0;
				int k = j;
				while (input[j][i] == input[k][i] && cnt < l && obstacle[k] == 0) {
					k--; cnt++;
					if (k < 0) break;
				}
				if (l == cnt) {
					if (j==n-2) answer++;

					for (int t = k+1; t <= j; t++)
						obstacle[t] = 1;

					continue;
				}
				else break;
			}
			//내려가는 경우
			else if (input[j][i]-1 == input[j+1][i]) {
				int cnt = 0;
				int k = j+1;
				while (input[j+1][i] == input[k][i] && cnt < l && obstacle[k] == 0) {
					k++; cnt++;
					if (n <= k) break;
				}
				if (l == cnt) {
					if (k == n) answer++;

					for (int t = j+1; t < k; t++)
						obstacle[t] = 1;

					j = k - 2;
					continue;
				}
				else break;
			}
			else break;
		}
	}

	cout << answer << '\n';
}
int main() {
	cin >> n >> l;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> input[i][j];
	solve();
}