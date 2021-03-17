#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// 정렬
bool solution(vector<string> phone_book) 
{
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size() - 1; i++) {
        if (phone_book[i + 1].find(phone_book[i]) == 0) {
            answer = false;
            break;
        }
    }

    return answer;
}

/*
// 해시
bool solution(vector<string> phone_book)
{
    bool answer = true;

    unordered_map<string, int> hash_map;
    for (int i = 0; i < phone_book.size(); i++) {
        hash_map[phone_book[i]] = 1;
    }

    for (int i = 0; i < phone_book.size(); i++) {
        string phone_number = "";
        for (int j = 0; j < phone_book[i].size(); j++) {
            phone_number += phone_book[i][j];
            if (hash_map[phone_number] && phone_number != phone_book[i])
                answer = false;
        }
    }

    return answer;
}
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> phone_book = { "119", "97674223", "1195524421" };

    cout << solution(phone_book);
    return 0;
}