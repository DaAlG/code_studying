using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#define MaxDish 3001

vector<int> dish;
int arr[MaxDish];
int n, d, k, c; //접시 수, 초밥의 가짓 수, 연속해서 먹는 접시 수, 쿠폰 번호
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> d >> k >> c;
	arr[c] = 1;
	int cnt = 1;
	int l = 0, r = k - 1;
	dish.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> dish[i];
		if (i < k) {
			arr[dish[i]]++;
			if (arr[dish[i]] == 1) cnt++;
		}
	}
	for (int i = 0; i < k; i++)
		dish.push_back(dish[i]);

	int answer = 0;
	while (1) {
		answer = max(answer, cnt);
		if (l == n) break;
		arr[dish[l]]--;
		if (arr[dish[l++]] == 0) cnt--;
		arr[dish[++r]]++;
		if (arr[dish[r]] == 1) cnt++;
	}
	cout << answer << '\n';
}