#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

//plus: 0, minus: 1, mul:2

long long ABS(long long num) {
	if (num < 0)
		return (-1) * num;
	else
		return num;
}

long long calculate(vector<int>num, vector<int> sign, int myCal[]) {
	int arr[3];//우선순위 저장. 계산 편하도록
	long long result = 0;

	//우선순위가 높을수록 0등에 가깝게 arr[plus] =0, arr[minus] = 1, arr[mul] = 2라면 plus>minus>mul 순이다.
	for(int i=0;i<3;i++)
		arr[myCal[i]] = i;

	for (int i = 0; i < 3; i++) { //i번째 부호를 계산하자
		for (int j = 0; j < sign.size(); j++) {
			result = 0;
			if (sign[j] == myCal[i] && i == arr[myCal[i]]) {
				switch (sign[j]) {
				case 0:
					result += num[j] + num[j + 1];
					break;
				case 1:
					result += num[j] - num[j + 1];
					break;
				case 2:
					result += num[j] * num[j + 1];
					break;
				}
				num.erase(num.begin() + j, num.begin() + j + 2);
				num.insert(num.begin() + j, result);
				sign.erase(sign.begin() + j);
				j--;
			}
		}
	}
	return result;
}

long long solution(string expression) {
	int myCal[3] = { 0, 1, 2 };
	long long answer = 0, result = 0;
	vector<int> num, sign;
	string s;

	sort(myCal, myCal + 3);

	for (int i = 0; i < expression.size(); i ++) {
		if (expression[i] == '-' || expression[i] == '+' || expression[i] == '*') {
			num.push_back(stoi(s));
			s = "";
			switch (expression[i]) {
			case '+':
				sign.push_back(0);
				break;
			case '-':
				sign.push_back(1);
				break;
			case '*':
				sign.push_back(2);
				break;
			}
		}
		else {
			s += expression[i];
		}
	}
	num.push_back(stoi(s));


	do {
		result = calculate(num, sign, myCal);
		if (answer <ABS(result)) answer = ABS(result);
	} while (next_permutation(myCal, myCal + 3));

	return answer;
}

int main() {
	string expression= "50*6-3*2";

	cout << solution(expression);
}