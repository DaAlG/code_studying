/*
 * 문자열 알고리즘
 * 16916 부분 문자열
 */

#include <iostream>
#include <string.h>
#define MAX 1000001
using namespace std;

char s[MAX], p[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s >> p;
	char* ptr = strstr(s, p);
	
	if (ptr != NULL)
		cout << 1;
	else
		cout << 0;

	return 0;
}