using namespace std;
#include <iostream>
#include <vector>

int n, k;
vector<pair<int, int>> c_top, c_bottom; //내구도, 로봇의 유무

bool check() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (c_top[i].first == 0) cnt++;
		if (c_bottom[i].first == 0) cnt++;
		if (cnt >= k) return true;
	}
	return false;
}
int main() {
	int x;
	cin >> n >> k;
	c_top.resize(n);
	c_bottom.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> x;
		c_top[i] = make_pair(x, 0);
	}
	for (int i = n - 1; i >= 0; i--) {
		cin >> x;
		c_bottom[i] = make_pair(x, 0);
	}
	int answer = 0;
	while (!check()) {
		answer++;
		//1. 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.내리는 위치에 있는 로봇은 내린다.
		//이동
		pair<int, int> t1 = c_top[n - 1], t2 = c_bottom[0];
		for (int i = n - 1; i > 0; i--) {
			c_top[i] = c_top[i - 1];
		}
		c_top[0] = t2;
		for (int i = 1; i < n; i++)
			c_bottom[i-1] = c_bottom[i];
		c_bottom[n - 1] = t1;
		//하차
		if (c_top[n - 1].second == 1) {
			c_top[n - 1].second = 0;
		}

		//2.
		for (int i = n-2; i >= 0; i--) {
			if (c_top[i].second != 0) {
				if (c_top[i + 1].first > 0 && c_top[i + 1].second == 0) {
					c_top[i + 1].second = c_top[i].second;
					c_top[i].second = 0;
					c_top[i + 1].first--;
					i++;
				}
			}
		}
		//하차
		if (c_top[n - 1].second != 0) {
			c_top[n - 1].second = 0;
		}

		//3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
		if (c_top[0].first > 0) {
			c_top[0].second = 1;
			c_top[0].first--;
		}
	}
	cout << answer << '\n';
}