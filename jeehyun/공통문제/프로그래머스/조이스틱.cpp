#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool visited[21];
int ans = 100000;

void dfs(string name, int now, int sum, int cnt)
{
    visited[now] = true;
    sum += min(name[now] - 'A', 'Z' - name[now] + 1);

    if (cnt == name.length()) {
        ans = min(ans, sum);
        return;
    }

    int move[] = { -1, 1 };

    for (int i = 0; i < 2; i++) {
        int next = now + move[i];
        if (i == 0 && next < 0) next += name.length();

        if (next >= name.length()) continue;

        int k = 1;
        if (visited[next]) {
            while (visited[next]) {
                next = next + move[i];
                if (i == 0 && next < 0) next += name.length();
                k++;
            }
        }

        if ((next >= 0 && next < name.length()) && !visited[next]) {
            dfs(name, next, sum + k, cnt + 1);
            visited[next] = false;
        }
    }
}

int solution(string name) {
    int answer = 0;
    int cnt = 0;

    // name에서 A 확인
    for (int i = 0; i < name.length(); i++) {
        if (name[i] == 'A') {
            visited[i] = true;
            cnt++;
        }
    }

    if (cnt != name.length()) {
        if (!visited[0])
            cnt++;

        dfs(name, 0, 0, cnt);
        answer = ans;
    }
    else // 모두 A로만 이루어져 있으면 조이스틱 조작 X
        answer = 0;

    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string name = "ABAAAAAAAAABB";

    cout << solution(name);
}