using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>

vector<int> Russia, Korea;
int answer[100];
int main() {
	int tc, n;
	vector<int>::iterator midx;
	int x;

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x;
			Russia.push_back(x);
		}
		for (int i = 0; i < n; i++) {
			cin >> x;
			Korea.push_back(x);
		}

		sort(Korea.begin(), Korea.end());
		midx = Korea.begin();
		for (int i = 0; i < n; i++) {
			vector<int>::iterator idx 
				= lower_bound(Korea.begin(), Korea.end(), Russia[i]);
			if (idx == Korea.end()) {
				answer[i] = *midx;
				Korea.erase(midx);
			}
			else {
				answer[i] = *idx;
				Korea.erase(idx);
			}	
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
			if (Russia[i] <= answer[i]) ans++;
		cout << ans << '\n';
		Korea.clear();
		Russia.clear();
	}
}