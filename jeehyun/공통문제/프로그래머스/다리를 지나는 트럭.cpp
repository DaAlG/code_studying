#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;

    queue<pair<int, int>> q; // weight, length
    q.push(make_pair(truck_weights[0], 1));
    int index = 1;

    while (!q.empty()) {
        int size = q.size();
        answer++;

        int sum = 0;

        // 트럭 이동
        for (int i = 0; i < size; i++) {
            int w = q.front().first;
            int len = q.front().second;
            q.pop();

            // 다리를 다 건너지 못한 경우 계속 이동
            if (len < bridge_length) {
                q.push(make_pair(w, len + 1));
                sum += w;
            }
        }

        // 다음 트럭의 무게를 견딜 수 있으면 다음 트럭 출발
        if (index < truck_weights.size() && sum + truck_weights[index] <= weight)
            q.push(make_pair(truck_weights[index++], 1));
    }

    return answer;
}

int main()
{
    int bridge_length = 100;
    int weight = 100;
    vector<int> truck_weights = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };

    cout << solution(bridge_length, weight, truck_weights);
    return 0;
}