#include <vector>
#include <iostream>
using namespace std;
#define MAX 3001

int e[MAX];

void erathos() {
    e[1] = 1;
    for (int i = 2; i < MAX; i++) {
        for (int j = i * 2; j < MAX; j += i) {
            if (e[j] == 1) continue;
            else e[j] = 1;
        }
    }
}
int solution(vector<int> nums) {
    int answer = 0;
    erathos();

    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int res = nums[i] + nums[j] + nums[k];
                if (e[res] == 0) answer++;
            }
        }
    }

    return answer;
}