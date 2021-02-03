/* 그래프
 * 9466 텀 프로젝트
 * 프로젝트 팀원 수에는 제한이 없다
 * 심지어 모든 학생들이 동일한 팀의 팀원인 경우와 같이 한 팀만 있을 수도 있다
 * 프로젝트 팀을 구성하기 위해, 모든 학생들은 프로젝트를 함께하고 싶은 학생을 선택해야 한다
 * (단, 단 한 명만 선택할 수 있다)
 * 혼자 하고 싶어하는 학생은 자기 자신을 선택하는 것도 가능하다
 * 학생들이 (s1, s2, ..., sr)이라 할 때,
 * s1이 s2를 선택하고, s2가 s3를 선택하고, ...sr이 s1을 선택하는 경우에만 한 팀이 될 수 있다
 * 주어진 선택의 결과를 보고 어느 프로젝트 팀에도 속하지 않는 학생들의 수 계산
 */

#include <iostream>
#include <cstring>
using namespace std;

int cnt;
int arr[100001];
bool cycle[100001]; // 방문이 끝났는지 여부 저장
bool visited[100001];

void dfs(int v)
{
	visited[v] = true;
	int next = arr[v];

	if (!visited[next]) {
		dfs(next);
	}
	else if (!cycle[next]) { // 이미 방문했지만 방문이 끝난 노드가 아니라면 사이클 
		// 사이클에 포함되는 노드들을 센다
		for (int i = next; i != v; i = arr[i])
			cnt++;
		// 자기 자신을 센다
		cnt++;
	}
	// 더 이상 해당 노드를 방문할 일이 없다
	cycle[v] = true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, n;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> n;
		memset(cycle, false, sizeof(cycle));
		memset(visited, false, sizeof(visited));

		for (int j = 1; j <= n; j++)
			cin >> arr[j];

		cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (!visited[j])
				dfs(j);
		}

		cout << n - cnt << "\n";
	}
	return 0;
}