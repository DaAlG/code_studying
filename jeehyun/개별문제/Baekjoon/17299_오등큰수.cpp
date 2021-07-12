/*
 * 자료구조
 * 17299 오등큰수
 */

#include <iostream>
#include <stack>
#define MAX 1000001
using namespace std;

int arr[MAX]; // 수열
int f[MAX]; // arr[i]가 수열 arr에서 등장한 횟수
int ngf[MAX]; // 오등큰수


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
		f[arr[i]]++;
		ngf[i] = -1;
	}

	st.push(arr[n - 1]);
	for (int i = n - 2; i >= 0; i--) {
		while (!st.empty()) {
			if (arr[i] != st.top() && f[arr[i]] < f[st.top()]) {
				ngf[i] = st.top();
				break;
			}
			else {
				st.pop();
			}
		}
		st.push(arr[i]);
	}

	for (int i = 0; i < n; i++) {
		cout << ngf[i] << ' ';
	}

	return 0;
}