using namespace std;
#include <iostream>

int visit[301], stairs[301], step[301][2];
int n;
int solution(int current) {
	int answer;
	step[1][0] = stairs[1];
	step[1][1] = -1;
	step[2][0] = stairs[1] + stairs[2];
	step[2][1] = stairs[2];

	for (int i = 3; i <= n; i++) {
		step[i][0] = step[i - 1][1] + stairs[i];
		step[i][1] = max(step[i - 2][0], step[i-2][1]) + stairs[i];
		
	}
	return answer = step[n][0] > step[n][1] ? step[n][0] : step[n][1];
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> stairs[i];
	cout << solution(0) << '\n';
}