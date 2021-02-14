#include <iostream>
#include <string>
#include <vector>

using namespace std;

int getDist(int from, int to)
{
	return abs(to - from) / 3 + abs(to - from) % 3;
}

string solution(vector<int> numbers, string hand)
{
	string answer = "";
	int left, right;
	left = 10, right = 12; // 왼손 위치 : *, 오른손 위치 : #

	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] == 0 || numbers[i] % 3 == 2) { // 2, 5, 8, 0일 때는 가까운 엄지
			if (numbers[i] == 0) numbers[i] = 11;
			// 세로 길이 + 가로 길이
			int l_dist = getDist(left, numbers[i]);
			int r_dist = getDist(right, numbers[i]);
			
			if (l_dist == r_dist) {
				if (hand == "right") {
					right = numbers[i];
					answer.append("R");
				}
				else {
					left = numbers[i];
					answer.append("L");
				}
			}
			else if (l_dist < r_dist) {
				left = numbers[i];
				answer.append("L");
			}
			else {
				right = numbers[i];
				answer.append("R");
			}
		}
		else if (numbers[i] % 3 == 0) { // 3, 6, 9는 오른손 엄지
			right = numbers[i];
			answer.append("R");
		}
		else { // 1, 4, 7은 왼손 엄지
			left = numbers[i];
			answer.append("L");
		}
	}

	return answer;
}

int main()
{
	vector<int> numbers = { 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 };
	string hand = "right";
	cout << solution(numbers, hand);
	return 0;
}