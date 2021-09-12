#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;
string expr;
int answer = INT_MIN;

int calc(char op, int a, int b)
{
	if (op == '+') return a + b;
	else if (op == '-') return a - b;
	return a * b;
}

int getResult(vector<int> p) 
{
	int idx = 0;
	int result = expr[0] - '0';

	if (!p.empty() && p[idx] == 0) idx++;

	for (int i = 1, cnt = 0; i < expr.size(); i++) {
		if (idx < p.size() && p[idx] == cnt + 1) { // 다음에 괄호가 오면
			int tmp = calc(expr[i + 2], expr[i + 1] - '0', expr[i + 3] - '0'); // 괄호를 먼저 계산하고
			result = calc(expr[i], result, tmp); // 그다음 결과 계산
			i += 3;
			cnt += 2;
			idx++;
		}
		else { // 괄호가 없으면
			result = calc(expr[i], result, expr[i + 1] - '0'); // 그냥 계산
			i++;
			cnt++;
		}
	}
	return result;
}

void go(vector<int> p, int now)
{
	if (now >= n / 2) {
		answer = max(answer, getResult(p));
		return;
	}
	
	go(p, now + 1); // 선택 X

	p.push_back(now);
	go(p, now + 2); // 선택
	p.pop_back();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> expr;
	go(vector<int>(), 0);
	cout << answer;
	return 0;
}