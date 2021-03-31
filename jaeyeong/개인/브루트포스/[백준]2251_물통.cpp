using namespace std;
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <set>
#include <algorithm>

int max_size[3];
int dir[6][2] = { {0,1},{1,0},{0,2},{2,0},{1,2},{2,1} };
set<tuple<int, int, int>> visit;
vector<int> answer;

void bfs() {
	queue<tuple<int, int, int>> q;
	int arr[3];

	q.push(make_tuple(0, 0, max_size[2]));
	visit.insert(make_tuple(0, 0, max_size[2]));

	while (!q.empty()) {
		int x, y, z;
		tie(x, y, z) = q.front();
		if (x == 0)
			answer.push_back(z);
		q.pop();
		
		for (int i = 0; i < 6; i++) {
			arr[0] = x;
			arr[1] = y;
			arr[2] = z;
			//[0] > [1]
			if (arr[dir[i][0]] == 0) continue;
			if (arr[dir[i][1]] < max_size[dir[i][1]]) {
				if (arr[dir[i][1]] + arr[dir[i][0]] <= max_size[dir[i][1]]) {
					arr[dir[i][1]] += arr[dir[i][0]];
					arr[dir[i][0]] = 0;
				}
				else {
					arr[dir[i][0]] -= (max_size[dir[i][1]] - arr[dir[i][1]]);
					arr[dir[i][1]] = max_size[dir[i][1]];
				}
			}
			tuple<int, int, int> t = make_tuple(arr[0], arr[1], arr[2]);
			if (visit.find(t) == visit.end()) {
				visit.insert(t);
				q.push(t);
			}
		}
	}
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << ' ';
	return;
}
int main() {
	cin >> max_size[0] >> max_size[1] >> max_size[2];
	bfs();
}