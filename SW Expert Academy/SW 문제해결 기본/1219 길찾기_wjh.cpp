// SW Expert Academy
// S/W 문제해결 기본 4일차 - 1219 길찾기

#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int test_case;
	int T = 10;
	const int size = 100;

	for (test_case = 1; test_case <= T; ++test_case) {
		int n;
		cin >> test_case >> n;

		int a[size] = { 0, };
		int b[size] = { 0, };
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			
			if (!a[x]) a[x] = y;
			else b[x] = y;
		}

		stack<int> s;
		bool visited[size] = { false, };

		int v = 0, w;
		int ans = 0;
		visited[v] = true;
		do {
			if (visited[a[v]] == false)
				w = a[v];
			else if (visited[b[v]] == false)
				w = b[v];
			else {
				s.pop();
				v = s.top();
				w = b[v];
			}
			s.push(v);

			while (w && visited[w] == false) {
				visited[w] = true;
				s.push(w);
				v = w;

				if (a[v] == 0) {
					s.pop();
					break;
				}

				if (visited[a[v]] == false)
					w = a[v];
				else if (visited[b[v]] == false)
					w = b[v];
				else
					s.pop();
			}

			if (w == size - 1) {
				ans = 1;
				break;
			}

			v = s.top();
			s.pop();
		} while (v);

		cout << "#" << test_case << " " << ans << endl;
	}

	return 0;
}