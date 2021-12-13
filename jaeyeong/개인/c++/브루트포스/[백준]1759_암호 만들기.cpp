using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

int l, c;
int visit[15], ans[15];
char v[15];
bool vowels[15];

void combination(int cnt, int idx) {
	if (cnt == l) {
		int cnt = 0;

		for (int i = 0; i < l; i++) 
			if (vowels[ans[i]]==true)	cnt++;
	
		if (cnt<=0 || (l-cnt)<2) return;


		for (int i = 0; i < l; i++)
			cout << v[ans[i]];
		cout << '\n';
		return;
	}
	for (int i = idx; i < c; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			ans[cnt] = i;
			combination(cnt + 1, i + 1);
			visit[i] = false;
		}
	}

}
int main() {
	cin >> l >> c;
	for (int i = 0; i < c; i++)
		cin >> v[i];

	sort(v, v + c);
	for (int i = 0; i < c; i++) {
		if (v[i] == 'a' || v[i] == 'e' || v[i] == 'o' || v[i] == 'u' || v[i] == 'i')
			vowels[i] = true;
	}
	combination(0, 0);
}