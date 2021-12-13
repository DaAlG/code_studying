using namespace std;
#include <iostream>
#include <queue>

int s;
int visit[1010][2020]; //screen, clipboard

void bfs() {
	queue < pair<int, pair<int, int>> > q; //시간, 화면, 클립보드
	visit[1][0] = true;
	q.push(make_pair(0, make_pair(1, 0)));
	while (!q.empty()) {
		int tim = q.front().first;
		int screen = q.front().second.first;
		int clip = q.front().second.second;
		q.pop();

		if (screen == s) {
			cout << tim << '\n';
			break;
		}

		if (0 < screen && screen < 1001) {
			//1 클립보드에 모두 복사
			if (!visit[screen][screen]) {
				visit[screen][screen] = true;
				q.push(make_pair(tim + 1, make_pair(screen, screen)));
			}
			//2. 클립보드 → 화면 붙여넣기
			if(clip>0 && (screen+clip)<1001)
			if (!visit[screen + clip][clip]) {
				visit[screen + clip][clip] = true;
				q.push(make_pair(tim + 1, make_pair(screen + clip, clip)));
			}
			//3. 하나 삭제
			if (!visit[screen - 1][clip]) {
				visit[screen - 1][clip] = true;
				q.push(make_pair(tim + 1, make_pair(screen - 1, clip)));
			}
		}
	}
	
}
int main() {
	cin >> s;
	bfs();
}