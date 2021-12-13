using namespace std;
#include <iostream>
#include <cstring>
#define MAX 100000
#define INF 0x3f3f3f3f

string s;
int dp[MAX];

//s[start..end] ������ ���̵� ��ȯ.
int classify(int start, int end) {
	string m = s.substr(start, end - start + 1);
	//1. ��� ���ڰ� ���� �� ���̵� 1
	if (m == string(m.size(), m[0])) return 1;
	//2. ���ڰ� 1�� ���� �����ϰų� ���� ������ �� ���̵� 2
	bool l2 = true;
	for (int i = 0; i < m.size() - 1; i++)
		if (m[i + 1] - m[i] != m[1] - m[0]) l2 = false;
	if (l2 == true && abs(m[1] - m[0]) == 1) return 2;
	//3. �� ���� ���ڰ� ������ ���� ������ �� ���̵� 4
	bool l3 = true;
	for (int i = 0; i < m.size(); i++)
		if (m[i] != m[i % 2]) l3 = false;
	if (l3 == true) return 4;
	//4. ���ڰ� ���� ������ �̷� �� ���̵� 5
	if (l2 == true) return 5;
	//5. �� ���� ��� ���̵� 10
	return 10;
}
int solve(int idx) {
	//������ ��
	if (idx == s.size()) return 0;
	//�޸������̼�
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