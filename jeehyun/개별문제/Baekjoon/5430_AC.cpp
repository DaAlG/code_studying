/*
 * 자료구조
 * 5430 AC
 */

#include <iostream>
#include <deque>
#include <string>
using namespace std;

deque<int> getArr(string s)
{
	deque<int> res;
	string tmp;

	for (int i = 1; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			tmp += s[i];
		}
		else {
			if (!tmp.empty())
				res.push_back(stoi(tmp));
			tmp.clear();
		}
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, n;
	cin >> T;

	for (int t = 0; t < T; t++) {
		string p, num;
		cin >> p >> n >> num;

		deque<int> arr = getArr(num);

		bool error = false;
		int flag = 1; // 1이면 원래 순서 그대로, 0이면 뒤집은 경우

		for (char ch : p) {
			if (ch == 'R') {
				flag = (flag + 1) % 2;
			}
			else if (ch == 'D') {
				if (arr.empty()) {
					cout << "error\n";
					error = true;
					break;
				}

				if (flag) // 원래 순서 그대로
					arr.pop_front();
				else // 숫자의 순서를 뒤집은 경우
					arr.pop_back();
			}
		}

		if (error) continue;

		cout << "[";
		if (!arr.empty()) {
			int size = arr.size();
			for (int i = 0; i < size; i++) {
				if (flag) {
					cout << arr.front();
					arr.pop_front();
				}
				else {
					cout << arr.back();
					arr.pop_back();
				}

				if (i != size - 1)
					cout << ',';
			}
		}
		cout << "]\n";
	}

	return 0;
}