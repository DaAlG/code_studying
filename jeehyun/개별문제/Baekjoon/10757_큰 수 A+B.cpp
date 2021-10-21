#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int carry[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a, b;
	cin >> a >> b;

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	if (a.size() < b.size())
		a.append(b.size() - a.size(), '0');
	else
		b.append(a.size() - b.size(), '0');

	string answer;
	for (int i = 0; i < a.size(); i++) {
		int sum = (a[i] - '0') + (b[i] - '0') + carry[i];
		carry[i + 1] = sum / 10;
		answer += sum % 10 + '0';
	}

	if (carry[a.size()])
		answer += "1";

	reverse(answer.begin(), answer.end());

	cout << answer;
	return 0;
}