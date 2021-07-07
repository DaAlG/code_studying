using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

//전략 1.	이분탐색
//전략 2.	투포인터
//전략 3.	bfs/dfs
//이것들을 조합해서 풀어야 하는 문제!
//★point: 방문한 칸 중 가장 높은 곳과 낮은 곳

typedef pair<int, int> pii;

int n;
vector<string> vil;
int h[50][50]; //고도
int cnt_k; //집의 개수
int x_post, y_post; //우체국의 위치
int dx[8] = {-1,1,0,0,-1,-1,1,1}; //상하좌우 대각선
int dy[8] = {0,0,-1,1,-1,1,1,-1};
vector<int> height;//높이를 모아놓은 배열

bool inRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

//low~ high의 고도 사이로 탐색을 했을 때, 배달 할 수 있는 집의 개수를 리턴
// bfs, dfs 중에 맘대로 쓰삼
int bfs(int low, int high) {
	int cnt = 0;
	bool visit[50][50] = { false, };
	queue<pii> q;
	q.push(pii(x_post, y_post));
	visit[x_post][y_post] = true;
	//시작점 체크를 안해서 실패했었다 ㅎ
	if (h[x_post][y_post] < low || high < h[x_post][y_post]) return -1;
	while (!q.empty() && cnt < cnt_k) {
		pii cur = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (!inRange(nx, ny)) continue;
			if (visit[nx][ny]) continue;
			if (h[nx][ny] < low || high < h[nx][ny]) continue;
			if (vil[nx][ny] == 'K') {
				cnt++;
			}
			visit[nx][ny] = true;
			q.push(pii(nx, ny));
		}
	}
	return cnt;
}

int main() {
	cin >> n;
	vil.resize(n);
	for (int i = 0; i < n; i++)
		cin >> vil[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (vil[i][j] == 'K') cnt_k++;
			else if (vil[i][j] == 'P') {
				x_post = i;
				y_post = j;
			}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> h[i][j];
			height.push_back(h[i][j]);
		}
	}

	//만약 방문할 칸 중 가장 높은 곳과 낮은 곳을 임의로 설정을 한다면?

	//하고 싶은 것
	//낮은 높이, 높은 높이를 임의로 정해서 모든 집에 배달 할 수 있는 지 확인하고 싶다
	//if(bfs(low, high) == cnt_k) ==> OK
	//low, high 모든 경우를 탐색하면 시간이 오래걸릴건데..
	//way 1. 이분 탐색을 이용 => hint: 특정 low에 대해서 low + 'a'를 찾아보기
	//way 2. 투 포인터를 이용 => hint: 특정 시점에서 low-high가 만족을 했을 때 다음 스텝은?

	sort(height.begin(), height.end());
	int answer = height.back()-height[0]; //(최대고도-최저고도)값이 가능한 가장 큰 답
	for (int low = 0, high = 0; low < height.size() && high < height.size() && low <= high; ) {
		if (bfs(height[low], height[high]) == cnt_k) {
			int tmp = height[high] - height[low];
			if (tmp < answer) answer = tmp;
			low++;
		}
		else {
			high++;
		}
	}
	cout << answer << '\n';
	return 0;
}