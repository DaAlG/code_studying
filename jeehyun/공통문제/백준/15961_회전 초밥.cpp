/*
 * BOJ 15961 회전 초밥
 */

#include <iostream>
#include <unordered_map>
#define MAX 3000000
using namespace std;

int sushi[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, d, k, c;
    cin >> n >> d >> k >> c;

    for (int i = 0; i < n; i++) {
        cin >> sushi[i];
    }

    unordered_map<int, int> dish;

    // k - 1개를 미리 넣어둔다
    for (int i = 0; i < k - 1; i++) {
        dish[sushi[i]]++;
    }

    int answer = 0;
    int start = 0;
    int end = k - 1;

    // 슬라이딩 윈도우
    for (int i = 0; i < n; i++) {
        // 1개 추가
        dish[sushi[(end++) % n]]++;

        // 초밥 종류의 최댓값 갱신
        int size = dish.size();
        if (dish.find(c) == dish.end())
            size++;
        answer = max(answer, size);

        // 제일 첫 초밥 제거
        int front = sushi[start++];
        dish[front]--;
        if (dish[front] == 0)
            dish.erase(front);
    }
    cout << answer;
    return 0;
}
