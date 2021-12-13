using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

bool compare(int a, int b) {
	return a > b;
}
int main() {
	int n, sum=0, maxV=-9999999, minV=999999;
	cin >> n;
	vector<int> v(n);
	int posCnt[4001] = { 0, }, negCnt[4001] = { 0, };
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];

		if (v[i] == 0) {
			posCnt[0]++; negCnt[0]++;
		}
		else if (v[i] > 0) posCnt[v[i]]++;
		else negCnt[v[i]*-1]++;
		maxV = max(maxV, v[i]);
		minV = min(minV, v[i]);
	}
	sort(v.begin(), v.end());
	vector<int> p3;
	int maxCnt = 0;
	for (int i = 0; i <= 4000; i++) {
		maxCnt = max(maxCnt, posCnt[i]);
		maxCnt = max(maxCnt, negCnt[i]);
	}
	for (int i = 0; i <= 4000; i++) {
		if (maxCnt == posCnt[i]) p3.push_back(i);
		if (maxCnt == negCnt[i] && i != 0) p3.push_back(-1 * i);
	}
	sort(p3.begin(), p3.end());
	int ans3;
	if (p3.size() == 1) ans3 = p3[0];
	else ans3 = p3[1];

	cout << round((double)sum / n) << '\n';
	cout << v[n / 2] << '\n';
	cout << ans3 << '\n';
	cout << maxV - minV << '\n';
}