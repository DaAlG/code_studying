//C++: https://velog.io/@jacob0122/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-N%EC%9C%BC%EB%A1%9C-%ED%91%9C%ED%98%84
//문제 이해: https://gurumee92.tistory.com/164
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
	int answer = -1;
	unordered_set<int> dp[8];
	int sum = 0;
	if (N == number) return answer = 1;
	for (int i = 0; i < 8; i++) {
		sum = sum * 10 + N;
		dp[i].insert(sum);
	}
	for (int i = 1; i < 8; i++) {
		for (int j = 0; j < i; j++) {
			for (auto& op1 : dp[j]) {
				for (auto& op2 : dp[i - j - 1]) {
					dp[i].insert(op1 + op2);
					dp[i].insert(op1 - op2);
					dp[i].insert(op1 * op2);
					if (op2 != 0) dp[i].insert(op1 / op2);
				}
			}
		}
		if (dp[i].count(number)) {
			answer = i + 1;
			break;
		}
	}
	return answer;
}

int main() {
	int N = 5;
	int number = 12;
	cout << solution(N, number);
}