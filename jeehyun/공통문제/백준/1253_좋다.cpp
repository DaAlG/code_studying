#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int a[2000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n < 3) {
        cout << 0;
        return 0;
    }

    int answer = 0;
    if (n >= 3) {
        // 오름차순으로 정렬
        sort(a, a + n);


        for (int i = 0; i < n; i++) {
            int left = 0;
            int right = n - 1;

            // 투 포인터로 합해서 a[i]가 되는 두 수를 찾는다
            while (left < right) {
                // i일 경우 넘어가기
                if (left == i || right == i) {
                    if (left == i) left++;
                    else if (right == i) right--;
                    continue;
                }

                int sum = a[left] + a[right];
                if (sum == a[i]) { // 합이 a[i]라면 종료
                    answer++;
                    break;
                }

                if (sum < a[i])
                    left++;
                else
                    right--;
            }
        }
    }
    cout << answer;
    return 0;
}
