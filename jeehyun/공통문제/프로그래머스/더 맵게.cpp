#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) 
{
    int answer = 0;

    // 우선순위 큐로 힙을 만든다
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

    // 가장 작은 값이 K 미만일 경우 음식을 섞는다
    while (pq.size() >= 2 && pq.top() < K) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();

        int newScov = a + b * 2;
        pq.push(newScov);

        answer++;
    }

    // 모든 음식의 스코빌 지수를 K 이상으로 만들 수 없는 경우
    if (pq.top() < K)
        answer = -1;

    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K = 7;
    vector<int> scoville = { 0, 0, 0, 0 };

    cout << solution(scoville, K); // -1
    return 0;
}