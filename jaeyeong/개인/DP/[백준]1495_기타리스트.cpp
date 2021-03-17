using namespace std;
#include <iostream>
#include <cstring>

int v[101], s, n, m, volume;
int cache[1001][101];

int solution(int volume, int index) {
	if (volume > m || volume < 0)
		return -100;
	if (index-1 == n)
		return volume;
	int& result = cache[volume][index];
	if (result != -1)
		return result;
	return result = max(solution(volume + v[index], index + 1), solution(volume - v[index], index + 1));
		
}
int main() {
	cin >> n >> s >> m;
	int answer;
	memset(cache, -1, sizeof(cache));
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	answer = solution(s, 1);
	if (answer == -100)
		cout << -1 << '\n';
	else
		cout << answer << '\n';
	return 0;
}