/*
 * 문자열
 * 1427 소트인사이드
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string a, string b)
{
	return a > b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<string> num;
	while (n) {
		num.push_back(to_string(n % 10));
		n /= 10;
	}

	sort(num.begin(), num.end(), cmp);

	string answer;
	for (string s : num) {
		answer += s;
	}
	cout << stoi(answer);

	return 0;
}