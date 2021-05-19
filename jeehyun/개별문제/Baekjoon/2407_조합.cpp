/*
 * DP
 * 2407 조합
 */

#include <iostream>
#include <string>
#include <algorithm>
#define MAX 101
using namespace std;

string nCr[MAX][MAX];

string addNum(string n1, string n2)
{
	long long sum = 0;
	string result;

	// 1의 자리부터 더한다
	while (!n1.empty() || !n2.empty() || sum) {
		if (!n1.empty()) {
			sum += n1.back() - '0';
			n1.pop_back();
		}

		if (!n2.empty()) {
			sum += n2.back() - '0';
			n2.pop_back();
		}

		// 다시 string 형태로 만들어서 push_back
		result.push_back((sum % 10) + '0');
		sum /= 10;
	}

	// 1의 자리부터 result에 넣었으므로 뒤집어준다
	reverse(result.begin(), result.end());
	
	return result;
}

// nCr = n-1Cr-1 + n-1Cr
string combination(int n, int r)
{
	if (n == r || r == 0)
		return "1";

	// 참조형 변수
	string& result = nCr[n][r];
	
	// 이미 계산했으면 바로 return (memoization 기법)
	if (result != "")
		return result;

	// 파스칼 삼각형 원리
	result = addNum(combination(n - 1, r - 1), combination(n - 1, r));
	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	cout << combination(n, m);

	return 0;
}