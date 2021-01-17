#include<iostream>
#include<cstring>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
bool prime[100001];
bool c[10001];
int d[10001];
int change(int num, int index, int digit) {
	if (index == 0 && digit == 0) return -1;
	string s = to_string(num);
	s[index] = digit + '0';
	return stoi(s);
}
int main() {
	for (int i = 2; i <= 10000; i++) {
		if (prime[i] == false)
			for (int j = i * i; j <= 10000; j += i)
				prime[j] = true;
	}
	for (int i = 0; i <= 10000; i++)
		prime[i] = !prime[i];
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		memset(c, false, sizeof(c));
		memset(d, 0, sizeof(d));
		d[n] = 0;
		c[n] = true;
		queue<int> q;
		q.push(n);
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for(int i=0;i<4;i++)
				for (int j = 0; j <= 9; j++) {
					int next = change(now, i, j);
					if(next!=-1)
						if (prime[next] && c[next] == false) {
							q.push(next);
							d[next] = d[now] + 1;
							c[next] = true;
						}
				}
		}
		cout << d[m] << '\n';
	}

	return 0;
}