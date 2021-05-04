using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int get10(int a) {
    int res = 0;
    while (1) {
        res++;
        if (a / 10 == 0)
            break;
        a -= a % 10; 
        a /= 10;
    }
    return res;
}

vector<int> makeVec(int a) {
    vector<int> arr;
    int res = 0;
    while (1) {
        res++;
        arr.push_back(a % 10);
        if (a / 10 == 0)
            break;
        a -= a % 10;
        a /= 10;
    }
    return arr;
}

bool check(int a, int b) {
    int an = get10(a);
    int bn = get10(b);
    int c;
    vector<int> arr;
    if (an <4) {
        arr = makeVec(a);
        c = an-1;
        for (int i = 0; i < (4- an); i++) {
            a *= 10;
            a += arr[c--];
            if (c < 0) c = an - 1;
        }
    }
    if(bn<4){
        arr = makeVec(b);
        c = bn - 1;
        for (int i = 0; i < (4- bn); i++) {
            b *= 10;
            b += arr[c--];
            if (c < 0) c = bn - 1;
        }
    }
    return a > b;
}
string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), check);
    if (numbers[0] == 0) return answer += "0";
    for (int i = 0; i < numbers.size(); i++) {
        answer += to_string(numbers[i]);
    }
    return answer;
}

int main() {
    vector<int> numbers = { 0,0,0,0,0 };
    cout << solution(numbers);
}