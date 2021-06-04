/*
 * 백트래킹
 * 7490 0 만들기
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
vector<string> answer;

void go(string s, int k, int res, int cnt, int flag)
{
	if (k > n) {
		if (res == 0)
			answer.push_back(s);
		return;
	}

	// 더하기
	go(s + '+' + to_string(k), k + 1, res + k, 1, 1);

	// 빼기
	go(s + '-' + to_string(k), k + 1, res - k, 1, 0);

	string tmp;

	// 이때까지 이어 붙인 숫자 구하기
	for (int i = k - cnt; i < k; i++) {
		tmp += to_string(i);
	}
	
	if (flag) { // 덧셈
		// 이전까지 이어 붙인 숫자만큼 빼준다
		res -= stoi(tmp);

		tmp += to_string(k);

		// 이어 붙인 숫자 더해주기
		res += stoi(tmp);
	}
	else { // 뺄셈
		// 이전까지 이어 붙인 숫자만큼 더해준다
		res += stoi(tmp);

		tmp += to_string(k);

		// 이어 붙인 숫자 빼주기
		res -= stoi(tmp);
	}

	// 숫자 이어 붙임
	go(s + ' ' + to_string(k), k + 1, res, cnt + 1, flag);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		cin >> n;
		go("1", 2, 1, 1, 1);

		sort(answer.begin(), answer.end());

		for (string s : answer) {
			cout << s << '\n';
		}
		cout << '\n';

		answer.clear();
	}

	return 0;
}