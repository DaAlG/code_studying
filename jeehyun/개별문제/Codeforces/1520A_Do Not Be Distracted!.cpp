#include <iostream>
#include <set>
using namespace std;

int main()
{
	int T, n;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> n;
		string polycarp;
		cin >> polycarp;

		bool suspicious = false;
		set<char> tasks;

		for (int i = 0; i < polycarp.size(); i++) {
			char task = polycarp[i];

			if (tasks.find(task) != tasks.end()) {
				suspicious = true;
				break;
			}
			else {
				tasks.insert(task);
			}

			while (polycarp[i + 1] == task) i++;
		}

		if (suspicious) cout << "NO\n";
		else cout << "YES\n";
	}

	return 0;
}