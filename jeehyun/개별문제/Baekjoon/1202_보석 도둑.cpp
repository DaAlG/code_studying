/*
 * 그리디
 * 1202 보석 도둑
 */

#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 300001

using namespace std;

struct gem {
	int m;
	int v;
};

gem g[MAX];
int c[MAX];

bool cmp(gem a, gem b)
{
	return a.m < b.m;
}

struct cmp2 {
	bool operator()(gem a, gem b) {
		if (a.v == b.v)
			return a.m < b.m;
		return a.v < b.v;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)	cin >> g[i].m >> g[i].v;
	for (int i = 0; i < k; i++) cin >> c[i];

	// 보석 무게를 오름차순으로 정렬
	sort(g, g + n, cmp);
	// 가방 최대 무게를 오름차순으로 정렬
	sort(c, c + k);

	long long answer = 0;
	int idx = 0;

	// 보석 가격을 내림차순, 가격이 같으면 무게를 내림차순으로 정렬
	priority_queue<gem, vector<gem>, cmp2> pq;
	for (int i = 0; i < k; i++) {
		// 보석을 가방에 담을 수 있을 때까지 넣어준다
		while (idx < n && g[idx].m <= c[i]) {
			pq.push(g[idx]);
			idx++;
			if (idx == n)
				break;
		}

		// 그 중에서 가격이 최대인 보석을 넣는다
		if (!pq.empty()) {
			answer += pq.top().v;
			pq.pop();
		}
	}
	cout << answer;
	return 0;
}