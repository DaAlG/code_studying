using namespace std;
#include <iostream>
#include <vector>
#include <cstring>
#define INF 1000000010

int dp[101][101];
//dp[i][j] = a개수 i, z개수 j일 때 나올 수 있는 조합의 수

int getAZ(int a, int z) {
	if (a == 0 || z == 0) return 1;
	if (dp[a][z] != -1) return dp[a][z];
	dp[a][z] = getAZ(a - 1, z) + getAZ(a, z - 1);
	if (dp[a][z] >= INF) dp[a][z] = INF;
	return dp[a][z];
}

string solve(int a, int z, int c) {
	//a,z: 사용가능한 a,z의 수
	//c번째 문자열을 구하자
	string answer = "";
	int total = a + z;
	for (int i = 0; i < total; i++) {
		if (a > 0) {
			int tmp = getAZ(a-1,z);
			if (tmp < c) {
				answer += 'z';
				c -= tmp;
				z--;
			}
			else {
				answer += 'a';
				a--;
			}
		}
		else {
			answer += 'z';
		}
	}
	return answer;
}
int main() {	
	int a, z, c;
	cin >> a >> z >> c;
	vector<char> v;

	memset(dp, -1, sizeof(dp));
	if (c > getAZ(a,z)) {
		cout << "-1\n";
		return 0;
	}

	cout << solve(a, z, c) << '\n';
	return 0;
}