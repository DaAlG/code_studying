using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

map<string, int> total;
int maxorder[11] = { 0 };

bool compare(string a, string b) {
    if (a.size() < b.size())
        return true;
    else if (a.size() > b.size())
        return false;
    if (a < b)
        return true;
    return false;
}

void combination(vector<char> arr, vector<char> comb, int r, int index, int depth, vector<int> course) {
    if (r == 0) {
        string temp = "";
        for (int i = 0; i < comb.size(); i++)
            temp += comb[i];
        sort(temp.begin(),temp.end());

        if (find(course.begin(), course.end(), temp.size()) != course.end())
            total[temp]++;
        if (maxorder[temp.size()] < total[temp])
            maxorder[temp.size()] = total[temp];
    }
    else if (depth == arr.size()) {
        return;
    }
    else {
        comb[index] = arr[depth];
        combination(arr, comb, r - 1, index + 1, depth + 1, course);
        combination(arr, comb, r, index, depth + 1, course);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    int current = 1;

    for (int i = 0; i < course.size(); i++) {
        for (int j = 0; j < orders.size(); j++) {
            vector<char> vec;
            vector<char> c(course[i]);
            for (int k = 0; k < orders[j].size(); k++)
                vec.push_back(orders[j][k]);
            combination(vec, c, course[i], 0, 0, course);
        }
        
    }

    map<string, int>::iterator iter;

    for (iter = total.begin(); iter != total.end(); iter++) {
        if (iter->second > 1 &&iter->second == maxorder[iter->first.size()])
            answer.push_back(iter->first);
    }



    return answer;
}

int main() {
    vector<string> ans;
    vector<string> orders = { "XYZ", "XWY", "WXA" };
    vector<int> course = { 2,3,4 };
    ans = solution(orders, course);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << '\n';
    }
}