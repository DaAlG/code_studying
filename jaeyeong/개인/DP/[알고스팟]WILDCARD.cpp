using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 101

//-1�� ���� ���� ������ �ʾ����� �ǹ��Ѵ�.
//1�� �ش� �Էµ��� ���� �������� �ǹ��Ѵ�.
//0�� �ش� �Էµ��� ���� �������� ������ �ǹ��Ѵ�.
int dp[MAX][MAX];
string w, s;

bool wildcard(int ww, int ss) {
	int& ret = dp[ww][ss];
	if (ret != -1) return ret;
	while (ww < w.size() && ss < s.size() && (w[ww] == '?' || w[ww] == s[ss])) {
		return ret = wildcard(ww + 1, ss + 1);
	}
	//���� ���� �����ؼ� �������: ���ڿ��� ������� ��.
	if (ww == w.size()) return ret = (ss == s.size());
	//0���� �����Ǵ� ���, �ѱ��� �����Ǵ� ��츦 ���ȣ���� ���� Ȯ�� ����
	if (w[ww] == '*') {
		if(wildcard(ww+1,ss) || (ss<s.size() && wildcard(ww,ss+1)) )
			return ret=1;
	}
	//�̿��� ��� ��� �������� �ʴ´�.
	return ret=0;
}
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> w;
		int n;
		cin >> n;
		vector<string> answer;
		for (int i = 0; i < n; i++) {
			memset(dp, -1, sizeof(dp));
			cin >> s;
			if (wildcard(0, 0)==1) answer.push_back(s);
		}
		sort(answer.begin(), answer.end());

		for (int i = 0; i < answer.size(); i++)
			cout << answer[i] << '\n';
	}
}