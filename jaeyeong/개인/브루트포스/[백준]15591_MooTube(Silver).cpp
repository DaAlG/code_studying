using namespace std;
#include <iostream>
#include <cstring>
#include <queue>
#define INF 0x3f3f3f3f

/*
* �ڹ����� ����, �������� ���������� ���ϴ� ���� �ָ�����
* �÷��̵带 �����ؼ� Ǯ�� �ð��ʰ��� ���� ����
* ��ü ����� �ּ� ���� �� ���ϰ� �õ��ϸ� �ð� �ʰ� 
* => ���� a -> c�� ���µ� ���� ��ΰ� a -> b , b -> c ��� a -> b �� k���� ���� �� �̹� a -> c�� k�̻��� ���� ���� �� ���� �ȴ�.
* ���� �̸� �̿��ؼ� ��� ������ �ּҰŸ� �̸� ã�� �ʿ� ���� Ž������ k �̻��̸� ť�� �ְ� ī��Ʈ �ø��� ������ ������ ��.
*/
int n, q;
int visit[5001];
vector<pair<int,int>> arr[5001];//���, ���絵

void bfs(int k, int v) {
	int cnt = 0;
	queue<int> q;
	visit[v] = 1;
	q.push(v);
	while (!q.empty()) {
		int c = q.front();
		q.pop();
		for (int i = 0; i < arr[c].size(); i++) {
			if (!visit[arr[c][i].first]) {
				if (arr[c][i].second >= k) {
					cnt++;
					visit[arr[c][i].first] = 1;
					q.push(arr[c][i].first);
				}
			}
		}
	}
	cout << cnt << '\n';
}
int main() {
	int a, b, c;
	cin >> n >> q;
	for (int i = 0; i < (n-1); i++) {
		cin >> a >> b >> c;
		arr[a].push_back(make_pair(b, c));
		arr[b].push_back(make_pair(a, c));
	}

	int k, v;
	while (q--) {
		memset(visit, 0, sizeof(visit));
		cin >> k>> v;
		bfs(k, v);
	}
	return 0;
}