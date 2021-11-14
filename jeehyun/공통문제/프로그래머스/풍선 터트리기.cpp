#include <string>
#include <vector>
#include <iostream>
#define endl "\n"

using namespace std;

int solution(vector<int> a) {
    int n = a.size();
    int answer = 1;

    int left = 0;
    int right = n - 1;
    int lMin = a[left];
    int rMin = a[right];

    while (left < right) {
        if (rMin > lMin) { // 오른쪽 최솟값이 왼쪽 최솟값보다 클 때
            if (a[--right] < rMin) {
                // a[right]가 rMin보다 작으면 끝까지 남을 수 있다
                answer++;
                rMin = a[right];
            }
        }
        else {
            if (a[++left] < lMin) {
                // a[left]가 lMin보다 작으면 끝까지 남을 수 있다
                answer++;
                lMin = a[left];
            }
        }
    }

    return answer;
}