using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 101

//-1은 아직 답이 계산되지 않았음을 의미한다.
//1은 해당 입력들이 서로 대응됨을 의미한다.
//0은 해당 입력들이 서로 대응되지 않음을 의미한다.
int dp[MAX][MAX];
string w, s;

bool wildcard(int ww, int ss) {
	int& ret = dp[ww][ss];
	if (ret != -1) return ret;
	while (ww < w.size() && ss < s.size() && (w[ww] == '?' || w[ww] == s[ss])) {
		return ret = wildcard(ww + 1, ss + 1);
	}
	//패턴 끝에 도달해서 끝난경우: 문자열도 끝났어야 함.
	if (ww == w.size()) return ret = (ss == s.size());
	//0글자 대응되는 경우, 한글자 대응되는 경우를 재귀호출을 통해 확인 가능
	if (w[ww] == '*') {
		if(wildcard(ww+1,ss) || (ss<s.size() && wildcard(ww,ss+1)) )
			return ret=1;
	}
	//이외의 경우 모두 대응되지 않는다.
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