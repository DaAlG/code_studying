using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

vector<int> arr, brr, v1, v2;
int main() {
	int t, n, m;
	cin >> t >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> m;
	brr.resize(m);
	for (int i = 0; i < m; i++)
		cin >> brr[i];

	//a로 만들 수 있는 부분합
	for (int i = 0; i < n; i++) {
		int sum = arr[i];
		v1.push_back(sum);
		for (int j = i + 1; j < n; j++) {
			sum += arr[j];
			v1.push_back(sum);
		}
	}
	//b로 만들 수 있는 부분합
	for (int i = 0; i < m; i++) {
		int sum = brr[i];
		v2.push_back(sum);
		for (int j = i + 1; j < m; j++) {
			sum += brr[j];
			v2.push_back(sum);
		}
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	long long answer = 0;
	for (int i = 0; i < v1.size(); i++) {
		int low = lower_bound(v2.begin(), v2.end(), t - v1[i]) - v2.begin();
		int top = upper_bound(v2.begin(), v2.end(), t - v1[i]) - v2.begin();
		answer += (top - low);
	}
	cout << answer << '\n';
	return 0;
}