/*
 * 프로그래머스 코딩테스트 연습
 * DFS/BFS
 * 타겟 넘버
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;


int total;

void dfs(vector<int>& numbers, int& target, int sum, int n)
{
	if (n >= numbers.size()) {
		if (sum == target)
			total++;
		return;
	}

	dfs(numbers, target, sum + numbers[n], n + 1);
	dfs(numbers, target, sum - numbers[n], n + 1);
}

int solution(vector<int> numbers, int target) 
{
	int answer = 0;

	queue<int> q;

	q.push(-numbers[0]);
	q.push(numbers[0]);

	for (int i = 1; i < numbers.size(); i++) {
		int curSize = q.size();
		for (int j = 0; j < curSize; j++) {
			int n = q.front();
			q.pop();

			q.push(n - numbers[i]);
			q.push(n + numbers[i]);
		}
	}

	while (!q.empty()) {
		if (q.front() == target)
			answer++;
		q.pop();
	}

	/*
	// DFS를 활용한 방법
	dfs(numbers, target, numbers[0], 1);
	dfs(numbers, target, -numbers[0], 1);

	answer = total;
	*/

	return answer;
}

int main()
{
	vector<int> numbers = { 1, 1, 1, 1, 1 };
	int target = 3;

	cout << solution(numbers, target);
	return 0;
}