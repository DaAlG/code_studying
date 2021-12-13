using namespace std;
#include <iostream>
#include <cstring>
#define MAX 100000
#define INF 0x3f3f3f3f

string s;
int dp[MAX];

//s[start..end] 구간의 난이도 반환.
int classify(int start, int end) {
	string m = s.substr(start, end - start + 1);
	//1. 모든 숫자가 같을 때 난이도 1
	if (m == string(m.size(), m[0])) return 1;
	//2. 숫자가 1씩 단조 증가하거나 단조 감소할 때 난이도 2
	bool l2 = true;
	for (int i = 0; i < m.size() - 1; i++)
		if (m[i + 1] - m[i] != m[1] - m[0]) l2 = false;
	if (l2 == true && abs(m[1] - m[0]) == 1) return 2;
	//3. 두 개의 숫자가 번갈아 가며 출현할 때 난이도 4
	bool l3 = true;
	for (int i = 0; i < m.size(); i++)
		if (m[i] != m[i % 2]) l3 = false;
	if (l3 == true) return 4;
	//4. 숫자가 등차 수열을 이룰 때 난이도 5
	if (l2 == true) return 5;
	//5. 그 외의 경우 난이도 10
	return 10;
}
int solve(int idx) {
	//수열의 끝
	if (idx == s.size()) return 0;
	//메모이제이션
	int& ret = dp[idx];
	if (ret != -1) return ret;
	ret = INF;
	for (int k = 3; k <= 5; k++) {
		if (idx + k <= s.size())
			ret = min(ret, solve(idx + k) + classify(idx, idx + k - 1));
	}
	return ret;
}
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		memset(dp, -1, sizeof(dp));
		cin >> s;
		cout<<solve(0)<<'\n';
	}
}