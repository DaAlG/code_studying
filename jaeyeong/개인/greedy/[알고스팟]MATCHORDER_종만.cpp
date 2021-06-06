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
			//���� �������� ���� �ѱ� ������ �̱� �� ���� ���
			//���� �������� ���� ������ ����Ų��.
			if (*ratings.rbegin() < Russia[r])
				ratings.erase(ratings.begin());
			//�� ���� ��� �̱� �� �ִ� ���� �� ���� �������� ���� ������ ����Ų��.
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