using namespace std;
#include <iostream>
#include <algorithm>
#define MAX 10000

int preorder[MAX];

void postorder(int start, int end) {
	if (start >= end) {
		return;
	}
	auto it = upper_bound(preorder + start, preorder + end, preorder[start]);
	int dist = it-preorder; //==distance(preorder,it) distance: iterator 사이의 크기를 반환한다.
	postorder(start + 1, dist);
	postorder(dist, end);
	cout << preorder[start] << '\n';
}
int main() {
	int n;
	int i = 0;
	while (!cin.eof()) {
		cin >> preorder[i++];
	}
	postorder(0, i-1);
}