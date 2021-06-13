using namespace std;
#include <iostream>
#include <cstring>
#include <limits>
#define MAX 101
const long long NEGINF = numeric_limits<long long>::min();

int a, b;
int arr[MAX], brr[MAX];
int dp[MAX][MAX];

//arr[adx]와 brr[bdx]에서 시작하는 합친 증가 부분 수열의 최대 길이를 반환
int solve(int adx, int bdx) { 
	int& ret = dp[adx + 1][bdx + 1];
	if (ret != -1) return ret;

	ret = 0;
	long long maxA = (adx == -1) ? NEGINF : arr[adx];
	long long maxB = (bdx == -1) ? NEGINF : brr[bdx];
	long long maxElement = max(maxA, maxB);

	for (int nextA = adx + 1; nextA < a; nextA++) {
		if(maxElement < arr[nextA])
			ret = max(ret, solve(nextA, bdx) + 1);
	}
	for (int nextB = bdx + 1; nextB < b; nextB++) {
		if (maxElement < brr[nextB])
			ret = max(ret, solve(adx, nextB) + 1);
	}
	return ret;
}
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		memset(dp, -1, sizeof(dp));
		cin >> a >> b;
		for (int i = 0; i < a; i++)
			cin >> arr[i];
		for (int i = 0; i < b; i++)
			cin >> brr[i];
		cout << solve(-1, -1) << '\n';
	}
}