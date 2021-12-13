using namespace std;
#include <iostream>
#include <string>

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	string s1 = to_string(a) + to_string(b);
	string s2 = to_string(c) + to_string(d);
	long long ab = stoll(s1);
	long long cd = stoll(s2);
	long long sum = ab + cd;
	cout << sum << '\n';
}