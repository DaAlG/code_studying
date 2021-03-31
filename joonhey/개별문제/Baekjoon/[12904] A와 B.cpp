#include <iostream>
#include <string>
using namespace std;

string reverseString(string str) {
    string res;
    for (int i = str.length() - 1; i >= 0; i--)
        //        res.append(str.substr(i, 1));
        res.push_back(str[i]);
    return res;
}

int main() {
    string S, T;
    getline(cin, S);
    getline(cin, T);
    int tSize;
    int sSize = S.length();

    //S는 고정.
    while ((tSize = T.length()) >= sSize) {

        //길이가 같아지는 순간 비교질
        if (tSize == sSize) {
            if (T.compare(S) == 0) {
                cout << 1;
                return 0;
            }
            else {
                cout << 0;
                return 0;
            }
        }
        //뒤에 A가 있으면 떼고
        if (T[tSize - 1] == 'A')
            T.erase(tSize-1, 1);
        else if (T[tSize - 1] == 'B') {
            T.erase(tSize - 1, 1);
            T = reverseString(T); //거꾸로
        }
        else {
            cout << 0;
            return 0;
        }
    }
    return 0;
}