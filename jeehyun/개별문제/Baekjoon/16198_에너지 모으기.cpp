/*
 * 브루트포스
 * 16198 에너지 모으기
 */

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int energy[10];
bool visited[10];

int go(int k, int sum) {

	if (k == 2)
		return sum;

	int maxi = 0;

	for (int i = 1; i < n - 1; i++) {
		if (visited[i]) continue;

		visited[i] = true;

		int left = i - 1;
		int right = i + 1;

		while (left >= 0 && visited[left]) left--;
		while (right < n && visited[right]) right++;

		maxi = max(maxi, go(k - 1, sum + energy[left] * energy[right]));
		visited[i] = false;
	}

	return maxi;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> energy[i];
	}
	cout << go(n, 0);
	return 0;
}