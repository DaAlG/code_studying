#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<int> v;

string solution(string number, int k) {
	int n = number.size();
	v.push_back(number[0] - '0');
	for (int i = 1; i < n; i++) {
		while (!v.empty() && v.back() < (number[i] - '0') ){
			if (k == 0) break;
			v.pop_back();
			k--;
		}
		v.push_back(number[i] - '0');
	}
	if (0<k) {
		for (int i = 0; i < v.size() - n + k; i++)
			v.pop_back();
	}
	string answer = "";
	for (int i = 0; i < v.size(); i++)
		answer += v[i] + '0';
	return answer;
}

int main() {
	string number = "1924";
	int k = 2;
	cout << solution(number, k);
}