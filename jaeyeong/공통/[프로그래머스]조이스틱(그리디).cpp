using namespace std;
#include <iostream>
#include <string>
#include <vector>

int isChecked[20] = { 0 };

int ABS(int n) {
	if (n < 0) return (-1) * n;
	else return n;
}

int length(char a) {
	int l = ABS(a - 'A');
	if (l < 'Z' - a + 1)
		return l;
	else
		return 'Z' - a + 1;
}

bool checkChecked(int n) {
	for (int i = 0; i < n; i++) {
		if (isChecked[i] == 0)
			return false;
	}
	return true;
}

int solution(string name) {
	int answer = 0, before=0, next = 0;
	int ctR = 0, ctL = 0, n = name.size();
	int nextL = n - 1, nextR = 1;
	vector<int> nameLength[20];


	for (int i = 0; i < n; i++) {
		nameLength[i].push_back( length(name[i]) );
		if (name[i] == 'A')
			isChecked[i] = 1;
	}
	answer += nameLength[0].back();
	isChecked[0] = 1;

	while(checkChecked(n)==false) {
		while (isChecked[nextR]==1) {
			if (nextR + 1 == name.size())
				nextR = 0;
			else
				nextR++;
			ctR++;
		}
		while (isChecked[nextL] == 1) {
			if (nextL - 1 == -1)
				nextL = name.size() - 1;
			else
				nextL--;
			ctL++;
		}
		if (ctL < ctR)
			next = nextL;
		else
			next = nextR;

		answer += nameLength[next].back();
		answer += ABS(before - next) < (n - ABS(before - next)) ? ABS(before - next) : (n - ABS(before - next));
		isChecked[next] = 1;
		before = next;
		nextL = next;
		nextR = next;
		ctR = 0; ctL = 0;
	}
	return answer;
}
int main() {
	string name = "JEROEN";
	cout << solution(name) << '\n';
}