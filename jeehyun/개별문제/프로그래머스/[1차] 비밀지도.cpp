#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string toBin(int n, int k) {
    string result;
    while (k != 0) {
        if (k % 2) result += "#";
        else result += " ";
        k /= 2;
    }

    while (result.size() < n) result += " ";

    reverse(result.begin(), result.end());
    return result;
}

string decode(string a, string b) {
    string result;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == ' ' && b[i] == ' ') result += " ";
        else result += "#";
    }
    return result;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for (int i = 0; i < n; i++) {
        answer.push_back(decode(toBin(n, arr1[i]), toBin(n, arr2[i])));
    }
    return answer;
}