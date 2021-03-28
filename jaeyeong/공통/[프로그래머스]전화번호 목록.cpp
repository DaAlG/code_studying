using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <map>

bool solution(vector<string> phone_book) {
	bool answer = true;
	int min_length = 30;
	map<string, int> m;

	for (int i = 0; i < phone_book.size(); i++) {
		m.insert(make_pair(phone_book[i], 0));
	}

	for (int i = 0; i < phone_book.size(); i++) {
		int size = phone_book[i].size();
		for (int j = 1; j <= size; j++) {
			string tofind = phone_book[i].substr(0, j);
			if (m.count(tofind) != 0 && phone_book[i].compare(tofind) !=0) {
				return answer = false;
			}
		}
	}
	return answer;
}
int main() {
	vector<string> phone_book = { "119", "97674223", "1195524421" };
	if(solution(phone_book)==false)
		cout << "false" << '\n';
	else
		cout << "true" << '\n';
}