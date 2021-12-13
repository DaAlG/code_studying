using namespace std;
#include <iostream>
#include <vector>
#include <cmath>

int n, maxK;
vector<int> input, output, cur;

void setMaxK() {
	for (int i = 2; i <= n; i *= 2)
		maxK++;
	return;
}

void setCur() {
	for (int i = 0; i < n; i++)
		cur[i] = input[i];
	return;
}

pair<vector<int>, int> move(vector<int> s, int start, int end) {
	vector<int> temp;
	for (int i = start; i <= start+end; i++)
		temp.push_back(s[i]);
	s.erase(s.begin() + start, s.begin() + start + end+1);
	int size = temp.size();
	temp.insert(temp.end(), s.begin(), s.end());
	return make_pair(temp, size);
}

vector<int> get(int k) {
	vector<int> s(n);
	pair<vector<int>, int> p;
	for (int i = 0; i < n; i++)
		s[i] = cur[i];

	int size = n;
	for (int i = 1; i <= (k+1); i++) {
		p = move(s, size - pow(2, k-i+1), pow(2, k-i+1)-1);
		s = p.first;
		size = p.second;
	}
	return s;
}

int main() {
	int a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		input.push_back(i+1);
		cin >> a;
		output.push_back(a);
		cur.push_back(i + 1);
	}

	setMaxK();

	for (int i = 1; i <= maxK; i++) {
		for (int j = 1; j <= maxK; j++) {
			setCur();
			cur = get(i);
			vector<int> res = get(j);
			for (int x = 0; x < n; x++){
				if (res[x] != output[x]) break;
				if (x == n - 1) {
					cout << i << ' ' << j << '\n';
					return 0;
				}
			}
		}
	}
}