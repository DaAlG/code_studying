#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());

    long long left = 0;
    long long right = times.back() * n; // 최대 시간

    while (left != right) {
        long long mid = (left + right) / 2;
        
        long long cnt = 0; // 심사 받을 수 있는 사람 수
        for (int i = 0; i < times.size(); i++) {
            cnt += mid / times[i];
        }

        if (cnt >= n) // 심사를 기다리는 사람보다 많으면 시간을 줄인다
            right = mid;
        else // 심사를 기다리는 사람보다 적으면 시간을 늘린다
            left = mid + 1;
    }

    return left;
}