using namespace std;
#include <iostream>
#include <vector>

int n;
vector<int> v;


int main() {
	int x, ans=0;
	cin >> n;
	
	v.push_back(-0x3f3f3f3f);
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (v.back() < x) {
			v.push_back(x);
			ans++;
		}
		else {
			auto it = lower_bound(v.begin(), v.end(), x);
			*it = x;
		}
	}
	cout << ans << '\n';
}