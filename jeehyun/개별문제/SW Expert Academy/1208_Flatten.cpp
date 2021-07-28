#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 1;

    for (int test_case = 1; test_case <= T; ++test_case) {
        int n;
        cin >> n;

        vector<int> box(100);
        for (int i = 0; i < box.size(); i++) cin >> box[i];

        for (int i = 0; i < n; i++) {
            auto minmax = minmax_element(box.begin(), box.end());
            box[minmax.first - box.begin()]++;
            box[minmax.second - box.begin()]--;
        }

        auto answer = minmax_element(box.begin(), box.end());
        cout << "#" << test_case << " " << (*answer.second - *answer.first) << "\n";
    }

    return 0;
}