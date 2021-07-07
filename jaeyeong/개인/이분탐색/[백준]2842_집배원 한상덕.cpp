using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

//���� 1.	�̺�Ž��
//���� 2.	��������
//���� 3.	bfs/dfs
//�̰͵��� �����ؼ� Ǯ��� �ϴ� ����!
//��point: �湮�� ĭ �� ���� ���� ���� ���� ��

typedef pair<int, int> pii;

int n;
vector<string> vil;
int h[50][50]; //��
int cnt_k; //���� ����
int x_post, y_post; //��ü���� ��ġ
int dx[8] = {-1,1,0,0,-1,-1,1,1}; //�����¿� �밢��
int dy[8] = {0,0,-1,1,-1,1,1,-1};
vector<int> height;//���̸� ��Ƴ��� �迭

bool inRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

//low~ high�� �� ���̷� Ž���� ���� ��, ��� �� �� �ִ� ���� ������ ����
// bfs, dfs �߿� ����� ����
int bfs(int low, int high) {
	int cnt = 0;
	bool visit[50][50] = { false, };
	queue<pii> q;
	q.push(pii(x_post, y_post));
	visit[x_post][y_post] = true;
	//������ üũ�� ���ؼ� �����߾��� ��
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

	//���� �湮�� ĭ �� ���� ���� ���� ���� ���� ���Ƿ� ������ �Ѵٸ�?

	//�ϰ� ���� ��
	//���� ����, ���� ���̸� ���Ƿ� ���ؼ� ��� ���� ��� �� �� �ִ� �� Ȯ���ϰ� �ʹ�
	//if(bfs(low, high) == cnt_k) ==> OK
	//low, high ��� ��츦 Ž���ϸ� �ð��� �����ɸ��ǵ�..
	//way 1. �̺� Ž���� �̿� => hint: Ư�� low�� ���ؼ� low + 'a'�� ã�ƺ���
	//way 2. �� �����͸� �̿� => hint: Ư�� �������� low-high�� ������ ���� �� ���� ������?

	sort(height.begin(), height.end());
	int answer = height.back()-height[0]; //(�ִ��-������)���� ������ ���� ū ��
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