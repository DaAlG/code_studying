using namespace std;
#include <iostream>
#include <vector>
#include <set>

vector<int> Russia, Korea;
int main() {
	int tc, n;
	int x;
	cin >> tc;
	while (tc--) {
		cin >> n;
		int wins = 0;
		for (int i = 0; i < n; i++) {
			cin >> x;
			Russia.push_back(x);
		}
		for (int i = 0; i < n; i++) {
			cin >> x;
			Korea.push_back(x);
		}
		multiset<int> ratings(Korea.begin(), Korea.end());
		for (int r = 0; r < n; r++) {
			//가장 레이팅이 높은 한국 선수가 이길 수 없는 경우
			//가장 레이팅이 낮은 선수와 경기시킨다.
			if (*ratings.rbegin() < Russia[r])
				ratings.erase(ratings.begin());
			//이 외의 경우 이길 수 있는 선수 중 가장 레이팅이 낮은 선수와 경기시킨다.
			else {
				ratings.erase(ratings.lower_bound(Russia[r]));
				wins++;
			}
		}
		cout << wins << '\n';
		Russia.clear();
		Korea.clear();
	}
}