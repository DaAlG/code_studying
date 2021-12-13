using namespace std;
#include <iostream>

int main() {
	int answer=0;
	int l, p, v, x=1;
	cin >> l >> p >> v;
	while (l != 0 && p != 0 && v != 0) {
		answer = (v / p) * l;
		if (v % p > l) answer += l;
		else answer += v % p;
		cout << "Case "<<x<<": "<<answer << '\n';
		x++;
		cin >> l >> p >> v;
	}
}