#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n;
vector<pair<int, int>> screw;
vector<pair<int, int>> answer;
vector<pair<int, int>> arr;
set<int> visited;

void go()
{
	bool possible = false;
	for (int next = 0; next < screw.size(); next++) {
		if (!visited.count(next) && (arr.empty() || screw[next].first == arr.back().second)) {
			possible = true;
			visited.insert(next);
			arr.push_back(screw[next]);

			go();

			visited.erase(next);
			arr.pop_back();
		}	
	}

	if (!possible && answer.size() < arr.size()) {
		answer = arr;
	}
}

int main()
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> n;

		for (int i = 0; i < n; i++) {
			int f, m;
			cin >> f >> m;
			screw.push_back({ f, m });
		}

		go();

		cout << "#" << test_case << " ";
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i].first << " ";
			cout << answer[i].second << " ";
		}
		cout << "\n";

		screw.clear();
		answer.clear();
	}
	return 0;
}