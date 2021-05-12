using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>

int n; //2~9
vector<char> input;
vector<int> v;

bool isRight() {
	int left = v[0], right = -1;
	for (int i = 1; i <= n; i++) {
		right = v[i];
		if (input[i - 1] == '>') {
			if (left <= right)
				return false;
		}
		else if (input[i - 1] == '<') {
			if (left >= right)
				return false;
		}
		left = right;
	}
	return true;
}
void solution(int m) {
	if (m == 1) { //max��
		do {
			if (isRight() == true) {
				for (int i = 0; i <= n; i++)
					cout << v[i];
				cout << '\n';
				return;
			}
		} while (prev_permutation(v.begin(), v.end()));
	}
	else { //min��
		do {
			if (isRight() == true) {
				for (int i = 0; i <= n; i++)
					cout << v[i];
				cout << '\n';
				return;
			}
		} while (next_permutation(v.begin(), v.end()));
	}
}
int main() {
	char x;
	cin >> n;
	v.resize(n+1, 0);
	input.resize(n, 0);
	int maxV = 1, minV = 0;

	//�ε�ȣ
	for (int i = 0; i < n; i++)
		cin >> input[i];

	//�ִ�
	for (int i =9; i >= 9-n; i--)
		v[9-i] = i;
	solution(maxV);

	//�ּڰ�
	for (int i = 0; i <= n; i++)
		v[i] = i;
	solution(minV);
}