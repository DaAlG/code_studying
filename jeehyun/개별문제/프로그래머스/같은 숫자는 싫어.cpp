#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer(arr.begin(), arr.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    return answer;
}