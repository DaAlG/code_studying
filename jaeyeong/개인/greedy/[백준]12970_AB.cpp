using namespace std;
#include <iostream>
#include <vector>

int n, k;
int main() {
	cin >> n >> k;
	for (int a = 0; a <= n; a++) {
		int b = n - a;
		if (a * b < k) continue;
		vector<int> cnt(b + 1);
		/*
		B가 4라면 A가 올 수 있는 칸은 다음 괄호들.()B()B)()B()B().
		즉 cnt[i]란 i번 위치에 A가 얼마나 들어가야 하는지 나타냄
		*/
		for (int i = 0; i < a; i++) {
			int x = min(b, k);
			cnt[x] += 1;
			k -= x;
		}
		for (int i = b; i >= 0; i--) {
			for (int j = 0; j < cnt[i]; j++) {
				cout << 'A';
			}
			if (i > 0) {
				cout << 'B';
			}
		}
		cout << '\n';
		return 0;
	}
	cout << "-1\n";
	return 0;
}