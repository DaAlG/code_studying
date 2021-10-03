#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#define INF 987654321
using namespace std;

struct Info {
	int l, r, d;
	Info(int l, int r, int d) : l(l), r(r), d(d) { }
};

int n;
vector<int> a;
vector<Info> infos;

int findMin(int start, int end)
{
	int minIdx = start;
	for (int i = start; i < end; i++) {
		if (a[i] < a[minIdx]) {
			minIdx = i;
		}
	}
	return minIdx;
}

void shiftingSort(int start, int end)
{
	deque<int> dq;
	for (int i = start; i <= end; i++) {
		dq.push_back(a[i]);
	}

	for (int i = 0; i < end - start; i++) {
		dq.push_back(dq.front());
		dq.pop_front();
	}

	for (int i = 0; i < dq.size(); i++) {
		a[start + i] = dq[i];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		cin >> n;

		a.resize(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		for (int i = 0; i < n; i++) {
			int idx = findMin(i, n);
			if (idx > i) {
				shiftingSort(i, idx);
				infos.push_back(Info(i + 1, idx + 1, idx - i));
			}
		}

		cout << infos.size() << "\n";
		for (auto &info : infos) {
			cout << info.l << " " << info.r << " " << info.d << "\n";
		}
		infos.clear();
	}
	return 0;
}