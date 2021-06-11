/* 
 * 분할 정복
 * 4779 칸토어 집합
 */

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string s;

void go(int start, int end)
{
	if (end - start == 1) return;

	int k = (end - start) / 3;
	for (int i = start + k; i < end - k; i++) {
		s[i] = ' ';
	}

	go(start, start + k);
	go(end - k, end);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;

	while (cin >> n) {
		int size = pow(3, n);
		
		s.clear();
		s.append(size, '-');
		
		go(0, size);
		cout << s << '\n';
	}
	
	return 0;
}