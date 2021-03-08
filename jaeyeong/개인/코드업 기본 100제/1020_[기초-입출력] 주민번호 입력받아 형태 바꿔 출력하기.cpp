#include <iostream>

using namespace std;
int main() {
	string str;
	cin >> str;
	auto idx = str.find("-");
	if (idx != -1) {
		cout << str.substr(0, idx) << str.substr(idx + 1);
	}
	else {
		cout << str;
	}
}