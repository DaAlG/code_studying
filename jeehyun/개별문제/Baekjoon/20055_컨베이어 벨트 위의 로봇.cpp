/*
 * 구현
 * 20055 컨베이어 벨트 위의 로봇 
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k;
queue<int> q;

void move(vector<int>& arr, vector<bool>& robot, int up, int down) {
	int size = q.size();

	for (int i = 0; i < size; i++) {
		int cur = q.front();
		robot[cur] = false;
		q.pop();

		if (cur == down) continue;

		int next = cur == 2 * n ? 1 : cur + 1;
		if (arr[next] > 0 && !robot[next]) {
			arr[next]--;
			if (next == down) continue;
			robot[next] = true;
			q.push(next);
		}
		else {
			robot[cur] = true;
			q.push(cur);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	vector<int> arr(2 * n + 1);
	vector<bool> robot(2 * n + 1);
	for (int i = 1; i <= 2 * n; i++) {
		cin >> arr[i];
	}

	int answer = 0;
	int up = 1;
	int down = n;

	while (1) {
		answer++;

		// 로봇과 함께 벨트 한 칸 회전
		up--; down--;
		if (up < 1) up = 2 * n;
		if (down < 1) down = 2 * n;

		// 가장 먼저 벨트에 올라간 로봇부터 벨트 회전 방향으로 한 칸 이동
		move(arr, robot, up, down);

		// 올리는 위치의 내구도가 0이 아니라면 로봇을 올린다
		if (!robot[up] && arr[up] > 0) {
			robot[up] = true;
			q.push(up);
			arr[up]--;
		}
		
		int cnt = 0;
		for (int i = 1; i <= 2 * n; i++) {
			if (arr[i] == 0)
				cnt++;
		}

		// 내구도가 0인 칸의 개수가 k개 이상이면 종료
		if (cnt >= k)
			break;
	}
	cout << answer;

	return 0;
}