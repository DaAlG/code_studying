using namespace std;
#include <iostream>
#include <string>

int main() {
	int tc;
	int h, w, n;
	cin >> tc;
	while (tc--) {
		cin >> h >> w >> n;
		int cnt = 1;
		int floor = 1, num = 1;
		while (cnt++ != n) {
			floor++;
			if (floor > h) {
				floor = 1;
				num++;
			}
		}
		string answer= to_string(floor);
		if (num < 10) answer += '0';
		answer += to_string(num);
		cout << answer << '\n';
	}
}