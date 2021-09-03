#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, double> a, pair<int, double> b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    vector<pair<int, double>> failure(N);
    vector<int> total(N);

    for (int k : stages) {
        if (k == N + 1) k--;
        else failure[k - 1].second++;
        for (int j = 1; j <= k; j++) {
            total[j - 1]++;
        }
    }

    for (int i = 0; i < N; i++) {
        failure[i].first = i + 1;
        if (total[i] == 0) failure[i].second = 0;
        else failure[i].second /= total[i];
    }
    sort(failure.begin(), failure.end(), cmp);

    for (int i = 0; i < N; i++) {
        answer.push_back(failure[i].first);
    }

    return answer;
}