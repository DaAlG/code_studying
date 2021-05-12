using namespace std;
#include <iostream>
#include <vector>

int n;
vector<int> num;
int cal[4]; // plus,minus,mul,div ¼ø
int visit[4];
int ansMax=-987654321, ansMin = 0x3f3f3f3f;

int calculate(vector<int> temp) {
	int sum = num[0];
	for (int i = 0; i < (n-1); i++) {
		switch (temp[i]) {
		case 0: //+
			sum = sum + num[i + 1];
			break;
		case 1: //-
			sum = sum - num[i + 1];
			break;
		case 2: //*
			sum = sum * num[i + 1];
			break;
		case 3: ///
			sum = sum / num[i + 1];
			break;
		}
	}
	return sum;
}
void solution(vector<int> temp, int depth) {
	if (depth == n) {
		int res = calculate(temp);
		ansMax = ansMax > res ? ansMax : res;
		ansMin = ansMin < res ? ansMin : res;
		return;
	}
	for(int i=0;i<4;i++)
	if (visit[i] != 0) {
		temp.push_back(i);
		visit[i]--;
		solution(temp, depth + 1);
		temp.pop_back();
		visit[i]++;
	}
}

int main() {
	vector<int> temp;
	cin >> n;
	num.resize(n);
	for (int i = 0; i < n; i++)
		cin >> num[i];
	for (int i = 0; i < 4; i++) {
		cin >> cal[i];
		visit[i] = cal[i];
	}
	solution(temp,1);
	cout << ansMax << '\n' << ansMin << '\n';
}