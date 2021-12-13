using namespace std;
#include <iostream>

int arr[1001][1001];
string a, b;

bool inRange(int x, int y) {
	return 1 <= x && x <= a.size() && 1 <= y && y <= b.size();
}

string getRes() {
	int x = a.size(), y = b.size(), cur;
	string res = "";
	while (inRange(x,y)) {
		cur = arr[x][y];
		if (cur == arr[x - 1][y]) x -= 1;
		else if (cur == arr[x][y - 1]) y -= 1;
		else {
			res = a[x-1] + res;
			x--; y--;
		}
	}
	return res;
}
int main() {
	cin >> b >> a;
	int asize = a.size();
	int bsize = b.size();
	//lcs
	for (int i = 1; i <= asize; i++) {
		for (int j = 1; j <= bsize; j++) {
			if (a[i - 1] == b[j - 1]) arr[i][j] = arr[i - 1][j - 1] + 1;
			else arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
		}
	}
	if (arr[asize][bsize] == 0) {
		cout << "0\n";
		return 0;
	}

	int ans1 = arr[asize][bsize];
	string ans2 = getRes();
	cout << ans1 << '\n' << ans2 << '\n';
	return 0;
}