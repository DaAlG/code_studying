#include <string>
#include <vector>
using namespace std;

int solution(vector<int> a) {
    vector<int> cnt(a.size() + 1);
    for (int i = 0; i < a.size(); i++) cnt[a[i]]++;

    int answer = -1;
    for (int i = 0; i < cnt.size(); i++) {
        if (cnt[i] == 0 || cnt[i] <= answer) continue;
        int result = 0;

        for (int j = 0; j < a.size() - 1; j++) {
            if (a[j] != i && a[j + 1] != i) continue;
            if (a[j] == a[j + 1]) continue;

            result++;
            j++;
        }
        answer = max(answer, result);
    }
    return answer * 2;
}