using namespace std;
#include <iostream>

struct person {
	int height, weight;
	int idx;
};
int n;
person input[50];
int result[50];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input[i].weight >> input[i].height;
		input[i].idx = i;
	}

	for (int i = 0; i < n; i++) {
		result[i] = 1;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (input[i].weight < input[j].weight &&
				input[i].height < input[j].height)
				result[i]++;
		}
	}
	for (int i = 0; i < n; i++)
		cout << result[i] << ' ';
}