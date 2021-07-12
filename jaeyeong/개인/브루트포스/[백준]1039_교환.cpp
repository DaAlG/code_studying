using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#define MAX 1000001

int n, k;
bool visit[MAX];

int conv(string buf, int l, int r) {
	//l과 r의 체크가 안되어 있음
	//처음에 num의 자리수는 정해져있기 때문에 그걸 이용하면 됨
	//arr
	//char buf[16];
	//sprintf(buf, "%d", num); //숫자를 문자열로 출력하는 방법
	swap(buf[l], buf[r]);
	//앞자리가 0이 아닌지 체크
	return stoi(buf);
}
int main() {
	cin >> n >> k;
	//예외가 되는 것들은 바로 처리
	// 1000000 ==> 그대로 답
	// 1~9 ==> 교환이 안됨 ==> -1
	// 10, 20, .., 90 ==> 교환이 안됨 ==> -1
	if (1 <= n && n <= 9) {
		cout << "-1\n";
		return 0;
	}
	else if (n == 10 || n == 20 || n == 30 || n == 40 || n == 50 || n == 60 ||
		n == 70 || n == 80 || n == 90) {
		cout << "-1\n";
		return 0;
	}
	//todo - 브루트포스
	//숫자를 직접 교환하는 로직
	//교환해서 단계별로 탐색해가는 로직
	//그리고 답 구하면 됨
	queue<int> q;
	q.push(n);

	for (int i = 0; i < k; i++) {
		//교환하고 탐색 ==> queue
		int sz = q.size();
		memset(visit, false, sizeof(visit));
		for (int j = 0; j < sz; j++) {
			int num = q.front();
			string num_s = to_string(num);
			q.pop();
			//교환 진행
			for (int a = 0; a < num_s.size(); a++) {
				for (int b = a + 1; b < num_s.size(); b++) {
					//교환 결과를 queue에 넣기
					//q에 중복해서 값이 들어갈 수 있기 때문에 중복체크
					//중복체크 방법 1. visit 배열을 이용
					//중복체크 방법 2. map을 이용
					if (a == 0 && num_s[b] == '0') continue;
					int x = conv(num_s, a, b);
					if (visit[x] == 0) {
						visit[x] = true;
						q.push(x);
					}
				}
			}

		}
	}
	//k번을 돌렸기 때문에 q에 남아 있는 것들은 k번을 수행하고 남은 숫잗르이고
	//q에 남은 것들 중 가장 큰 값이 답이다.
	int answer = q.front();
	int sz = q.size();
	while (sz--) {
		answer = max(answer, q.front());
		q.pop();
	}
	cout << answer << '\n';
	return 0;
}