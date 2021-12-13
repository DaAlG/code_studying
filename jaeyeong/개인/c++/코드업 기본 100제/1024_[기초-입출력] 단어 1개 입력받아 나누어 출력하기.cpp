#include <iostream>

using namespace std;
int main() {
	char str[30];
	scanf("%s", str);
	for (int i = 0;; i++) {
		if (str[i] == '\0')
			break;
		printf("'%c'\n", str[i]);
	}
}