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