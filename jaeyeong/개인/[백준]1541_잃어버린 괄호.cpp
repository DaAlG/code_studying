#include <iostream>
#include <string>
using namespace std;


int main() {
	string s, temp="";
	int result = 0;
	bool minus = false;
	cin >> s;
	for (int i = 0; i <= s.size(); i++) {
		if (s[i] == '+' || s[i] == '-' || s[i] == '\0') {
			if (minus == true)
				result += -stoi(temp);
			else
				result += stoi(temp);
			temp = "";
			if (s[i] == '-') minus = true;
			continue;
		}
		temp += s[i];
	}
	printf("%d", result);
	return 0;
}