using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

pair<int,int> meeting[100000];
int n;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}

int main() {
	int x, y;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		meeting[i] = make_pair(x, y);
	}

	int current_end = 0;
	int answer = 0;
	sort(meeting, meeting + n, compare);
	for (int i = 0; i < n; i++) {
		if (current_end <= meeting[i].first) {
			answer++;
			current_end = meeting[i].second;
		}
	}
	cout << answer << '\n';

} 