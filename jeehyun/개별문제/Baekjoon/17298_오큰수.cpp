/*
 * 자료구조
 * 17298 오큰수
 */

#include <iostream>
#include <stack>
#define MAX 1000001
using namespace std;

int arr[MAX];
int nge[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	stack<int> st;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		nge[i] = -1;
	}

	st.push(arr[n - 1]);
	for (int i = n - 2; i >= 0; i--) {
		while (!st.empty()) {
			if (arr[i] < st.top()) {
				nge[i] = st.top();
				break;
			}
			else {
				st.pop();
			}
		}
		st.push(arr[i]);
	}

	for (int i = 0; i < n; i++) {
		cout << nge[i] << ' ';
	}

	return 0;
}