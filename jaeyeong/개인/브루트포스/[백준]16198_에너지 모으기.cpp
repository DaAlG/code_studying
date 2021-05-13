using namespace std;
#include <iostream>

int stone[10];
int n;

int beforeNode(int idx, bool alive[]) {
	for (int i = idx - 1; 0 < i; i--)
		if (alive[i] == true)
			return i;
}
int nextNode(int idx, bool alive[]) {
	for (int i = idx + 1; i < (n-1); i++)
		if (alive[i] == true)
			return i;
}
int solution(int cnt, bool alive[], int sum) {
	if (cnt >= n-2) return sum;

	int answer=-1;
	int checkcnt = 0;
	for (int i = 1; i < (n-1); i++) {
		if (alive[i] == false) continue;
		if (checkcnt == n - 2) continue;
		alive[i] = false;
		checkcnt++;
		int res = solution(cnt + 1, alive, sum+(stone[beforeNode(i,alive)]*stone[nextNode(i,alive)]));
		alive[i] = true;
		if (answer == -1) answer = res;
		else answer = max(answer, res);
	}
	return answer;
}
int main() {
	bool alive[10];
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> stone[i];
		alive[i] = 1;
	}
	cout<<solution(0, alive, 0)<<'\n';
}