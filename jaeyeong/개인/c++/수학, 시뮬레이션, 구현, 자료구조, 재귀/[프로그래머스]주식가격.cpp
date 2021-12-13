using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <stack>

vector<int> solution(vector<int> prices) {
    stack<pair<int,int>> st;
    int size = prices.size();
    vector<int> answer(size);

    int num = 1;
    st.push(make_pair(num++,prices[0]));
    for (int i = 1; i < size; i++) {
        while (!st.empty() && st.top().second > prices[i]) {
            answer[st.top().first - 1] = num - st.top().first;
            st.pop();
        }
        st.push(make_pair(num++, prices[i]));
    }
    num = size;
    while (!st.empty()) {
        answer[st.top().first - 1] = num - st.top().first;
        st.pop();
    }
    return answer;
}

int main() {
    vector<int> prices = { 1,2,3,2,3 };
    vector<int> ans = solution(prices);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    return 0;
}