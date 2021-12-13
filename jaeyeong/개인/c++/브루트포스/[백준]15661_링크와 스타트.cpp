using namespace std;
#include <iostream>
#include <vector>

int n, ans=0x3f3f3f3f;
int skill[21][21];
int arr[21],visit[21];

int getDiff(int k) {
	int brr[21] = { 0 }, ta = 0, tb = 0;
	vector<int> teamA, teamB;
	int size;

	for (int i = 1; i <= k; i++)
		brr[arr[i]] = 1;
	for (int i = 1; i <= n; i++) {
		if (brr[i] == 0) teamB.push_back(i);
		else teamA.push_back(i);
	}

	size = teamA.size();
	for (int i = 0;i<size; i++) {
		for (int j = i + 1; j < size; j++) {
			ta += skill[teamA[i]][teamA[j]];
			ta += skill[teamA[j]][teamA[i]];
		}
	}
	size = teamB.size();
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			tb += skill[teamB[i]][teamB[j]];
			tb += skill[teamB[j]][teamB[i]];
		}
	}
	if (ta > tb) return ta - tb;
	else return tb - ta;
}

void comb(int k, int cnt) {
	if (cnt == k) {
		int dif = getDiff(k);
		if (dif < ans) ans = dif;
	}
	for (int i = arr[cnt] + 1; i <= n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			arr[cnt + 1] = i;
			comb(k, cnt + 1);
			if (ans == 0) return;
			visit[i] = false;
		}
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> skill[i][j];
		}
	}
	for (int i = 2; i < n; i++)
		comb(i, 0);
	cout << ans << '\n';
}